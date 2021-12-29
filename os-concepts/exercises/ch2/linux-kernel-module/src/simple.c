/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
    printk(KERN_INFO "Loading Module\n");

    printk(KERN_INFO "golden ratio prime: %lu\n", GOLDEN_RATIO_PRIME);
    printk(KERN_INFO "jiffies: %llu\n", get_jiffies_64());
    printk(KERN_INFO "HZ: %d\n", HZ);
    
    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
    printk(KERN_INFO "Removing Module\n");

    unsigned long greatest_common_divisor = gcd(3300, 24);

    printk(KERN_INFO "gcd of 3300 and 24: %lu\n", greatest_common_divisor);
    printk(KERN_INFO "jiffies: %llu\n", get_jiffies_64());
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

