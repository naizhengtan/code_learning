/*
 * Using "func 100000", it can be 23% faster on my machine.
 *perf:
 *  args 198885835
 *  template 152302803
 *  speedup 0.234220
 */
#include "stdio.h"
#include "stdint.h"
#include "string"

int do_arg(int a, int b, int c, int d, bool sum) {
	if (sum) {
		return (a+b+c+d);
	} else {
		return 0;
	}
}

template <bool sum>
int do_template(int a, int b, int c, int d) {
	if (sum) {
		return (a+b+c+d);
	} else {
		return 0;
	}
}

int do_arg(int a, bool sum) {
	if (sum) {
		return a;
	} else {
		return 0;
	}
}

template <bool sum>
int do_template(int a) {
	if (sum) {
		return a;
	} else {
		return 0;
	}
}


__inline__ uint64_t rdtsc() {
	uint32_t low, high;
	__asm__ __volatile__ (
						  "xorl %%eax,%%eax \n    cpuid"
						  ::: "%rax", "%rbx", "%rcx", "%rdx" );
	__asm__ __volatile__ (
						  "rdtsc" : "=a" (low), "=d" (high));
	return (uint64_t)high << 32 | low;
}

int main(int args, char** argv) {
	if (args!=2) {
		printf("Usage: func <num>\n");
		return 0;
	}
	
	int times = stoi(std::string(argv[1])); 
	uint64_t b_arg = rdtsc();
	for(int i=0; i<times; i++) {
		do_arg(i, true);
		//do_arg(i,i*2, i*4, i*8, true);
	}
	for(int i=0; i<times; i++) {
		do_arg(i, false);
		//do_arg(i,i*2, i*4, i*8, false);
	}
	uint64_t e_arg = rdtsc();

	uint64_t b_temp = rdtsc();
	for(int i=0; i<times; i++) {
		do_template<true>(i);
		//do_template<true>(i,i*2, i*4, i*8);
	}
	for(int i=0; i<times; i++) {
		do_template<false>(i);
		//do_template<false>(i,i*2, i*4, i*8);
	}
	uint64_t e_temp = rdtsc();

	printf("perf:\n\targs %llu\n\ttemplate %llu\n\tspeedup %f\n", 
		   (e_arg-b_arg), (e_temp-b_temp), 
		   ((e_arg-b_arg)-(e_temp-b_temp))/(double)(e_arg-b_arg)  );
}
