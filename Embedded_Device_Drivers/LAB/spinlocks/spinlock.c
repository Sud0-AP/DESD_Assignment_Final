#include <linux/init.h> // __init and __exit
#include <linux/module.h> // module_init() module_exit() mandatory header
#include <linux/kernel.h> //pr_info()
#include <linux/kthread.h> // kernel thread API kthread_create()
#include <linux/spinlock.h> // provides spinlock APIs
#include <linux/completion.h> // for completion mechanism and thread syncronisations
#include <linux/delay.h> // delay APIs like udelay and msleep
#include <linux/smp.h> // provides multicore helper APIs
#include <linux/moduleparam.h> // Allows passing parameters when insterting modules 

static unsigned long shared_counter; //shared variable between threads

static spinlock_t counter_lock; //spinlock variable to save shared variable

static struct task_struct *thread1; // each thread in kernel is represented by task_struct
static struct task_struct *thread2; // used by kthread_create()

static DECLARE_COMPLETION(start_signal); // completion variable used for synchronized exectuion
					 // start signal makes both thread wait unitll module
					 // init allow them to start
static DECLARE_COMPLETION(done_thread1); // Tells module tinit that thread1 and 2 has finished
static DECLARE_COMPLETION(done_thread2); 

static unsigned int loops = 1000000; // this variable tells how many times each threads imcrements
				     // shared counter

module_param(loops, uint, 0444); //This allow loops to pass through command line using insmod
				 //0444 means the parameter is readable from sysfs
				 //but not writable after module loading
MODULE_PARM_DESC(loops, "Number of increments per thread");

static int use_lock = 1; // 1 = use spin lock, 0 = dont use spin lock
module_param(use_lock, int, 0444);
MODULE_PARM_DESC(use_lock, "Use spinlocks 1 = yes, 0 = no");

static int worker_function(void *arg){ //routine function for both threads
	long id = (long) arg;
	unsigned int i;
	unsigned long temp;

	pr_info("spin_demo: Thread %ld waiting on CPU %d\n", id, smp_processor_id());

	//both threads wait here, they will start together when module init calls complete_all()
	//without this function thread1 can start before thread 2, that will reduce chances of race around.
	//this makes both thread start at the same time
	wait_for_completion(&start_signal);

	pr_info("spin_demo: Thread %ld started on CPU %d\n", id, smp_processor_id());

	for(i=0; i<loops; i++){
		if(use_lock){
			spin_lock(&counter_lock);
			++shared_counter;
			spin_unlock(&counter_lock);
		}else{
			//read this variable directly from memory
			temp = READ_ONCE(shared_counter);
			if((i%1000) == 0){
				udelay(1);
			}
			++temp;
			WRITE_ONCE(shared_counter, temp);
		}
	}
	pr_info("spin_demo: Thread %ld finished on CPU %d\n", id, smp_processor_id());
	if(id == 1){
		complete(&done_thread1);
	}else{
		complete(&done_thread2);
	}

	return 0;
}

static int __init spin_demo_init(void){
	unsigned long expected; // stores expected value of shared counter
	int cpu0, cpu1; //variable number for cpu cores
	pr_info("spin_demo: module loaded\n");
	shared_counter = 0;
	spin_lock_init(&counter_lock);

	pr_info("spin_demo: use_lock = %d\n", use_lock);
	pr_info("spin_demo: loops per thread = %d\n", loops);
	pr_info("spin_demo: online cpus = %u\n", num_online_cpus()); // num of CPUs available
	
	// creates kernel thread, worker function, argument passed to worker function 
	// and name of the kernel thread
	thread1 = kthread_create(worker_function, (void*) 1, "spin_threads1");
	if(IS_ERR(thread1)){
		pr_err("spin demo: failed to create thread 1\n");
		return PTR_ERR(thread1);
	}

	thread2 = kthread_create(worker_function, (void*) 2, "spin_threads2");
	if(IS_ERR(thread2)){
		pr_err("spin demo: failed to create thread 2\n");
		return PTR_ERR(thread2);
	}

	cpu0 = cpumask_first(cpu_online_mask); // cpu_online_mask contains all CPUs
	cpu1 = cpumask_next(cpu0, cpu_online_mask);

	pr_info("spin_demo: CPU Online Mask = %*pbl\n", cpumask_pr_args(cpu_online_mask));
	if(cpu1 < nr_cpu_ids){
		kthread_bind(thread1, cpu0);
		pr_info("spin_demo: Thread1 bound to cpu %d\n", cpu0);
		kthread_bind(thread2, cpu1);
		pr_info("spin_demo: Thread2 bound to cpu %d\n", cpu1);
	}else{
		pr_warn("spin_demo: Only one CPU online, race around can still happen due to preemption but might not be visible.\n");
	}

	wake_up_process(thread1); //kthread_create() threads in sleeping mode
	wake_up_process(thread2); // this function makes them runnable. now execution jumps to
				  // wait_for_completion(&start_signal);
	msleep(100); //wait for 100 miliseconds
	
	pr_info("spin_demo: starting both threads together\n");

	complete_all(&start_signal); // wake all threads waiting on start signal
				     // both threads starts incrementing now
	wait_for_completion(&done_thread1);
	wait_for_completion(&done_thread2);

	expected = 2UL*loops;
	pr_info("spin_demo: expected counter = %lu\n", expected);
	pr_info("spin_demo: actual counter = %lu\n", shared_counter);

	if(shared_counter == expected){
		pr_info("spin_demo: RESULT: correct output\n"); 
	}else{
		pr_info("spin_demo: RESULT: race condition detected\n"); 
	}

	return 0;
}

static void __exit spin_demo_exit(void){
	pr_info("spin_demo: module unloaded\n");
}

module_init(spin_demo_init);
module_exit(spin_demo_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Neel");
MODULE_DESCRIPTION("Beginers spinlocks");
