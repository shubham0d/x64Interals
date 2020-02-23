#include <linux/init.h>
#include <linux/module.h>
#include <linux/const.h>
#include <linux/errno.h>


static inline uint64_t get_gdt_base1(void)
{
	struct desc_ptr gdt;
	__asm__ __volatile__("sgdt %[gdt]"
			     : /* output */ [gdt]"=m"(gdt));
	return gdt.address;
}


static inline uint64_t get_gdt_limit(void)
{
	struct desc_ptr gdt;
	__asm__ __volatile__("sgdt %[gdt]"
			     : /* output */ [gdt]"=m"(gdt));
	return gdt.size;
}

int __init start_init(void)
{
	
    uint64_t gdt_base = get_gdt_base1();
    uint64_t gdt_limit = get_gdt_limit();
    uint64_t *disc_address;
    uint64_t descriptor;
    int no_of_descriptor;
    int i;
    printk(KERN_INFO "Address of gdt is %llx\n", (long long)gdt_base);
    printk(KERN_INFO "Limit of gdt is %llx\n", (long long)gdt_limit);
    //need to change in future since descritor size can be 8 bytes
    // or 16 bytes(system descriptor)
    no_of_descriptor = gdt_limit/8;
	for (i = 0; i<no_of_descriptor; i++){
		disc_address = gdt_base + (i*8);
		descriptor = *disc_address;
		printk(KERN_INFO "Value in descriptor no %d is %llx\n",i, (long long)descriptor);
	}

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
