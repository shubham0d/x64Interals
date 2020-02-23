#include<stdio.h>

int main(){
	short int cs;
	short int ds;
	short int gs;
	short int ss;
	short int es;
	short int fs;

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


    printf("Data in CS segement is - 0x%x\n",cs);
	printf("Data in DS segement is - 0x%x\n",ds);
	printf("Data in GS segement is - 0x%x\n",gs);
	printf("Data in FS segement is - 0x%x\n",fs);
	printf("Data in SS segement is - 0x%x\n",ss);
	printf("Data in ES segement is - 0x%x\n",es);

    return 0;
}
