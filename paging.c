#include <linux/init.h>
#include <linux/module.h>
#include <linux/const.h>
#include <linux/errno.h>

// getting the value of cr3 register

int __init start_init(void)
{
    uint64_t cr3;

	__asm__ __volatile__("mov %%cr3, %[cr3]"
			     : /* output */ [cr3]"=r"(cr3));

    printk(KERN_INFO "Data in CR3 is - 0x%llx\n",cr3);
    //PML4 value starts from lower 13th bit to the higher end
    cr3 = cr3 >> 12;
    printk(KERN_INFO "Address of PML4 table is - 0x%llx\n",cr3);
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
MODULE_DESCRIPTION("CRO register ");
