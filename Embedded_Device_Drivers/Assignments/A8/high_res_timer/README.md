# Assignment 8: High-Resolution Kernel Timer

## Overview
Demonstrates high-resolution kernel timers using `struct hrtimer`. Timer increments a global counter every 500 milliseconds with nanosecond precision and is readable via character device.

## Key APIs
- `hrtimer_init()` - Initialize hrtimer with clock source and mode
- `hrtimer_start()` - Start hrtimer with ktime_t interval
- `hrtimer_forward_now()` - Reschedule timer for next expiration
- `hrtimer_cancel()` - Stop hrtimer
- `HRTIMER_RESTART` - Return value to make timer periodic

## Testing
```bash
cd A8/high_res_timer
make
sudo insmod high_timer.ko
cat /dev/high_timer_dev          # Output: hrtimer_count = 1
sleep 2
cat /dev/high_timer_dev          # Output: hrtimer_count = 5
sudo rmmod high_timer
```

## Important Question: Why HRTimer is Preferred for Better Timing Precision

**Answer:**
- **Nanosecond granularity:** Uses `ktime_t` instead of jiffy-based intervals
- **Independent of tick rate:** Works identically regardless of CONFIG_HZ setting
- **Hardware support:** Leverages HPET, TSC, or other high-resolution clock sources
- **Better accuracy:** Typically ±1-10 microseconds vs ±5-10 milliseconds for low-res
- **Real-time suitable:** Essential for multimedia, precise measurements, and real-time applications
- **Monotonic clock:** `CLOCK_MONOTONIC` prevents anomalies from system time adjustments

**Concepts:** `struct hrtimer`, `ktime_t`, soft-IRQ context, nanosecond precision, hardware timers
