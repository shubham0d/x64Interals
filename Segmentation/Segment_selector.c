#include <linux/init.h>
#include <linux/module.h>
#include <linux/const.h>
#include <linux/errno.h>


int __init start_init(void)
{
	uint16_t cs;
	uint16_t ds;
	uint16_t gs;
	uint16_t ss;
	uint16_t es;
	uint16_t fs;

	__asm__ __volatile__("mov %%cs, %[cs]"
			     : /* output */ [cs]"=rm"(cs));
	__asm__ __volatile__("mov %%ds, %[ds]"
		 		 : /* output */ [ds]"=rm"(ds));
	__asm__ __volatile__("mov %%gs, %[gs]"
				 : /* output */ [gs]"=rm"(gs));
	__asm__ __volatile__("mov %%ss, %[ss]"
			 	 : /* output */ [ss]"=rm"(ss));
	__asm__ __volatile__("mov %%es, %[es]"
			 	: /* output */ [es]"=rm"(es));
	__asm__ __volatile__("mov %%fs, %[fs]"
				: /* output */ [fs]"=rm"(fs));


    printk(KERN_INFO "Data in CS segement is - 0x%x\n",cs);
	printk(KERN_INFO "Data in DS segement is - 0x%x\n",ds);
	printk(KERN_INFO "Data in GS segement is - 0x%x\n",gs);
	printk(KERN_INFO "Data in FS segement is - 0x%x\n",fs);
	printk(KERN_INFO "Data in SS segement is - 0x%x\n",ss);
	printk(KERN_INFO "Data in ES segement is - 0x%x\n",es);

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
