#include "sys/time.h"
#include "stdio.h"

int main() {
	struct timeval begin, end;
	gettimeofday(&begin, NULL);
	int a,b,c,d;
	for(int i=1;i<100000;i++){
		a = a + i;
		b = b - a;
		c = a * b;
		d = c / i;
	}
	gettimeofday(&end, NULL);
	printf("time costing: %ld ms\n", 
		   (end.tv_sec - begin.tv_sec)*1000 + (end.tv_usec - begin.tv_usec) );
}
