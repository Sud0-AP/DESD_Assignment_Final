# Assignment 5: Buffer Mutex Synchronization

## Overview
Demonstrates mutex-based synchronization for protecting a shared kernel buffer. Multiple processes can read/write, but mutex ensures only one accesses the buffer at a time.

## Key APIs
- `mutex_init()` - Initialize mutex at module load
- `mutex_lock()` - Acquire lock (blocks if held by another process)
- `mutex_unlock()` - Release lock
- `IS_ERR() / PTR_ERR()` - Error handling for pointer-returning functions
- Character device with automatic /dev node creation

## Testing
```bash
cd A5/buffer_mutex
make
sudo insmod buffer_mutex.ko
cat /dev/buffer_mutex            # Read buffer
echo "Hello" > /dev/buffer_mutex # Write to buffer
cat /dev/buffer_mutex            # Read again
sudo rmmod buffer_mutex
```

## Important Concepts
- **Mutex vs Spinlock:** Mutex allows sleeping; suitable for regions with potential blocking operations
- **Critical Section:** Buffer read/write operations protected from concurrent access
- **Context:** Module loads with empty buffer, initialized during `my_init()`
- **Device Class:** Automatic /dev/buffer_mutex node creation for user access
