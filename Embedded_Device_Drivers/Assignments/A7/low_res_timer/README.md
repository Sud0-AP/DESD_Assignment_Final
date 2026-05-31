# Assignment 7: Low-Resolution Kernel Timer

## Overview
Demonstrates low-resolution kernel timers using `struct timer_list`. Timer increments a global counter every 1 second and is readable via character device.

## Key APIs
- `timer_setup()` - Initialize timer
- `mod_timer()` - Schedule/reschedule timer with jiffies-based delays
- `del_timer_sync()` - Stop timer and wait for completion
- `msecs_to_jiffies()` - Convert milliseconds to timer ticks

## Testing
```bash
cd A7/low_res_timer
make
sudo insmod low_timer.ko
cat /dev/low_timer_dev           # Output: timer_count = 1
sleep 3
cat /dev/low_timer_dev           # Output: timer_count = 4
sudo rmmod low_timer
```

## Important Question: Why Low-Resolution Timers Are Unsuitable for Microsecond-Level Delays

**Answer:**
- Timer precision limited by **jiffy period** (1-10 ms typical, depending on CONFIG_HZ)
- Cannot fire more frequently than system tick rate
- Even requesting 100 µs delay will wait until next jiffy interrupt (~milliseconds)
- Accuracy typically ±5-10 ms; sub-millisecond timing is unreliable
- Interrupt-driven delivery with variable latency makes precise timing impossible

**Concepts:** `struct timer_list`, `jiffies`, periodic re-arming, interrupt context callbacks
