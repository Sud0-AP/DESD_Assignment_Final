#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define STDIN_FD 0
#define STDOUT_FD 1
#define STDERR_FD 2


void main(){
	int ret_val;
	char input_buff[128] = {0};

	ret_val = read(STDIN_FD, (void *) input_buff, sizeof(input_buff) - 1);
	if (ret_val == -1){
		printf("Read Operation failed : %d\n", errno);
		return;
	}

	printf("Read : %d bytes\n", ret_val);
	printf("String Recived %s\n", input_buff);

	char *write_msg = "This was printed using the write function from the unistd library\n";

	ret_val = write(STDOUT_FD, (const void *) write_msg, strlen(write_msg));
	if (ret_val == -1){
		printf("Write Operation failed : %d\n", errno);
		return;
	}

	printf("written : %d bytes\n", ret_val);
}
