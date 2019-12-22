/* This is a sample program to test the working of CR0.WP (Write protected).
 CR0.WP decides if the supervisor mode(kernel) will able to write to RO(Read only)
 structure or not.
 If CR0.WP = 1 --> kernel can not write to any read only page.
 If CR0.WP = 0 --> kernel can write to a read only page.
*/

#include <linux/module.h>  /* Needed by all modules */
#include <linux/kernel.h>  /* Needed for KERN_ALERT */
#include <linux/init.h>         /* Needed for the macros */
#include <linux/proc_fs.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/init.h>
#include <linux/pci.h>
#include <linux/slab.h>

// Comment the line 32(setting WP = 0) and load the driver.
// A General protection fault will going to occur because "a" points
// to a read only string "Hello" and `a[2]='a'` is trying to write another
// value to the second character.
// In second attempt leave the 32th line uncommented and load the driver.
// The string will successfully get replaced with "Hallo".
static int __init start_init(void)
{
    uint64_t cr0;
    char *a = "Hello";
	__asm__ __volatile__("mov %%cr0, %[cr0]"
			     : /* output */ [cr0]"=r"(cr0));
    printk(KERN_INFO "Initial value of 'a' is %s\n", a );
    // Will set the CR0.WP flag to 0.
    cr0 = cr0 & 0xFFFFFFFFFFFEFFFF;
    __asm__ __volatile__("mov %0, %%cr0" : : "r"(cr0) : "memory");

    a[2] = 'a';
    printk(KERN_INFO "Updated value in 'a' is %s\n", a );
    return 0;
}

static void __exit end_exit(void)
{
    printk(KERN_INFO "Unloading the driver\n");
	return;
}

module_init(start_init);
module_exit(end_exit);


MODULE_LICENSE("GPL V3");
MODULE_AUTHOR("Shubham Dubey");
MODULE_DESCRIPTION("Memory protection test ");
