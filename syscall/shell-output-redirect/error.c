#include "stdio.h"
#include "fcntl.h"

int main(){
	printf("This is std out.\n");
	int fd = open("file-do-not-exist",O_WRONLY);
	perror("This is std error:");
}
