// SPDX-License-Identifier: GPL-2.0

#include <linux/module.h>          /* MODULE_LICENSE, MODULE_AUTHOR */
#include <linux/platform_device.h> /* platform_driver, platform_device */
#include <linux/of.h>              /* of_device_id */
#include <linux/gpio/consumer.h>   /* GPIO descriptor API */
#include <linux/timer.h>           /* timer_list, timer_setup */
#include <linux/jiffies.h>         /* jiffies, msecs_to_jiffies */
#include <linux/property.h>        /* device_property_read_u32 */
#include <linux/slab.h>            /* devm_kzalloc */

/*
 * Driver private data.
 * One object of this structure is created for one LED device.
 */
struct bbb_ext_led {
    struct gpio_desc *led_gpio;    /* GPIO descriptor for external LED */
    struct timer_list blink_timer; /* Kernel timer used for blinking */
    unsigned int period_ms;        /* Blink period in milliseconds */
    bool led_state;                /* Current logical LED state */
};

/*
 * Timer callback.
 *
 * This function runs periodically.
 * It toggles the LED and rearms the timer.
 *
 * Important:
 * Kernel timer callback runs in softirq/atomic context.
 * Therefore, we must not use GPIO APIs that can sleep.
 */
static void bbb_ext_led_timer_cb(struct timer_list *t)
{
    struct bbb_ext_led *led;

    led = from_timer(led, t, blink_timer);

    led->led_state = !led->led_state;

    gpiod_set_value(led->led_gpio, led->led_state);

    mod_timer(&led->blink_timer,
              jiffies + msecs_to_jiffies(led->period_ms));
}

/*
 * Device-managed cleanup function.
 *
 * This runs automatically when the platform device is removed
 * or when the driver is unloaded.
 */
static void bbb_ext_led_cleanup(void *data)
{
    struct bbb_ext_led *led;

    led = data;

    del_timer_sync(&led->blink_timer);

    gpiod_set_value(led->led_gpio, 0);
}

/*
 * probe() is called when:
 *
 * 1. Device Tree creates a platform device with:
 *      compatible = "sud0,GPIO"
 *
 * 2. This driver contains the same compatible string in of_match_table.
 */
static int bbb_ext_led_probe(struct platform_device *pdev)
{
    struct device *dev;
    struct bbb_ext_led *led;
    u32 period;
    int ret;

    dev = &pdev->dev;

    dev_info(dev, "BBB external LED probe called\n");

    led = devm_kzalloc(dev, sizeof(*led), GFP_KERNEL);
    if (!led)
        return -ENOMEM;

    /*
     * Request GPIO from Device Tree.
     *
     * con_id = "led"
     *
     * This maps to Device Tree property:
     *      led-gpios = <&gpio1 28 0>;
     *
     * GPIOD_OUT_LOW configures the GPIO as output
     * with initial logical value 0.
     */
    led->led_gpio = devm_gpiod_get(dev, "led", GPIOD_OUT_LOW);
    if (IS_ERR(led->led_gpio))
        return dev_err_probe(dev,
                             PTR_ERR(led->led_gpio),
                             "failed to get led GPIO\n");

    /*
     * Timer callback cannot sleep.
     * Therefore, reject GPIO controllers that require sleeping access.
     *
     * AM335x internal GPIO is memory-mapped, so this should normally pass.
     */
    if (gpiod_cansleep(led->led_gpio))
        return dev_err_probe(dev,
                             -EINVAL,
                             "GPIO can sleep; cannot use timer callback\n");

    led->period_ms = 500;

    ret = device_property_read_u32(dev, "blink-period-ms", &period);
    if (!ret && period > 0)
        led->period_ms = period;

    led->led_state = false;

    timer_setup(&led->blink_timer, bbb_ext_led_timer_cb, 0);

    platform_set_drvdata(pdev, led);

    ret = devm_add_action_or_reset(dev, bbb_ext_led_cleanup, led);
    if (ret)
        return ret;

    mod_timer(&led->blink_timer,
              jiffies + msecs_to_jiffies(led->period_ms));

    dev_info(dev, "external LED blinking started, period=%u ms\n",
             led->period_ms);

    return 0;
}

/*
 * Device Tree match table.
 */
static const struct of_device_id bbb_ext_led_of_match[] = {
    { .compatible = "sud0,GPIO" },
    { }
};

MODULE_DEVICE_TABLE(of, bbb_ext_led_of_match);

/*
 * Platform driver object.
 */
static struct platform_driver bbb_ext_led_driver = {
    .probe = bbb_ext_led_probe,
    .driver = {
        .name = "my_gpio_led",
        .of_match_table = bbb_ext_led_of_match,
    },
};

module_platform_driver(bbb_ext_led_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ayan Rahul");
MODULE_DESCRIPTION("BeagleBone Black external LED blink driver using GPIO descriptor API");
