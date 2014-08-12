#include "stdio.h"
#include "fcntl.h"
#include "sys/stat.h"

int main(){
	umask(0777);
	int fd = open("_tmp",O_CREAT|O_TRUNC|O_WRONLY,0644);
	if(fd==-1){
		perror("umask");
	}
}
