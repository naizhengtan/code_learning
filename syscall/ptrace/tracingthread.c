#include "stdio.h"
#include <sys/types.h>
#include <sys/ptrace.h>
#include "errno.h"
#include "stdlib.h"

int main(){
	int pid = 0;
	scanf("%d",&pid);
	printf("%d\n",pid);

	char *errorstr = malloc(1024);
	int re = ptrace(PT_ATTACH,pid,0,0);
	printf("%d\n",re);
	perror(errorstr);
	printf("%s\n",errorstr);

	re = ptrace(PT_KILL,pid,(caddr_t)1,9);
	printf("%d\n",re);
	perror(errorstr);
	printf("%s\n",errorstr);
}
