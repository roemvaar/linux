/*
 * hello_world.c - Kernel module that accepts a name as command line
 * argument and print hello <name>
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static char *name = "world";
module_param(name, charp, 0000);


static int __init hello_world_init(void)
{
	printk(KERN_INFO KBUILD_MODNAME ": Hello %s!\n", name);
	return 0;
}


static void __exit hello_world_exit(void)
{
	printk(KERN_INFO KBUILD_MODNAME ": Good bye %s!\n", name);
}


/* Register the module */
module_init(hello_world_init);
module_exit(hello_world_exit);


/* Information about the module */
MODULE_AUTHOR("Roberto Valenzuela");
MODULE_DESCRIPTION("Kernel module that accepts command line arguments");
MODULE_LICENSE("GPL");
MODULE_PARM_DESC(name, "Name to be printed as greeting!");
