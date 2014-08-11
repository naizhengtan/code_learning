#include "stdio.h"
#include <sys/types.h>
#include <sys/ptrace.h>


int main(){

	int i = 0;
	//i = ptrace(PT_DENY_ATTACH,0,0,0);
	//i = ptrace(PT_TRACE_ME,0,0,0);
	printf("%d\n",i);

	int counter = 0;
	while(1){
		counter++;
		printf("%d\n",counter);
		sleep(1);
	}
}
