# Assignment 6: Counting Semaphore

## Overview
Demonstrates counting semaphore for limiting concurrent access to multiple character devices. Allows up to 3 concurrent device opens; additional opens block until one closes.

## Key APIs
- `semaphore` structure with `NUM_DEVICE_ALLOWED` counter (3)
- `down_interruptible()` - Decrement semaphore; block if zero (in open)
- `up()` - Increment semaphore; wake one waiting process (in release)
- `container_of()` - Retrieve device structure from cdev pointer
- `file->private_data` - Store device pointer for read/write access

## Testing
```bash
cd A6/counting_semaphore
make
sudo insmod count_sem.ko
cat /dev/count_sem0 &            # Open device 0
cat /dev/count_sem1 &            # Open device 1
cat /dev/count_sem2 &            # Open device 2
cat /dev/count_sem3              # Blocks: all 3 slots occupied
# (Ctrl+C previous commands to free slots)
sudo rmmod count_sem
```

## Important Concepts
- **Counting Semaphore:** Controls resource access count (3 devices max)
- **down_interruptible():** Returns -ERESTARTSYS if signal received during wait
- **Mutex + Semaphore:** Semaphore limits concurrent opens; mutex protects per-device buffer
- **Multi-device:** 4 device nodes (minor 0-3) each with own buffer
- **Resource Management:** Prevents resource exhaustion by limiting concurrent users
