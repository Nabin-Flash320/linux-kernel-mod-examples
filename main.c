#include <linux/module.h> // Required for all kernel modules
#include <linux/kernel.h> // Required for KERN_INFO
#include <linux/init.h>   // Required for the macros
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

// Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nabin-Flash320");
MODULE_DESCRIPTION("A Simple Hello World Kernel Module");

static short int int_val = 10;

module_param(int_val, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(int_val, "Integer value that holds the short int type value from command line");

// Function that executes when the module is loaded
static int __init hello_init(void)
{
    /*
        Shortcut to:
        printk(KERN_INFO fmt...);
    */
    pr_info("Command line arg for int_val %d\n", int_val);
    return 0; // Return 0 if successful
}

// Function that executes when the module is removed
static void __exit hello_exit(void)
{
    pr_info("Goodbye, World! Kernel Module Unloaded.\n");
}

// Register the entry and exit points of the module
module_init(hello_init);
module_exit(hello_exit);

