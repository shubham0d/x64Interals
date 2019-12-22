#include <linux/init.h>
#include <linux/module.h>
#include <linux/const.h>
#include <linux/errno.h>


int __init start_init(void)
{
    uint64_t rflag;

    __asm__ __volatile__ ("pushfq; popq %[rflag]"
		: [rflag]"=rm"(rflag));

    printk(KERN_INFO "Value in RFLAG is - 0x%llx\n",(long long)rflag);
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
MODULE_DESCRIPTION("EFLAG");
