#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"

int main(){
	int fd = open("alphabet",O_RDWR|O_APPEND);

	int r = lseek(fd,0,SEEK_SET);
	if(r<0){
		perror("lseek:");
		return 0;
	}
	int pos = lseek(fd,0,SEEK_CUR);
	printf("After lseek, the cursor is %d\n",pos);

	char buf[10];
	r = read(fd,buf,10);
	printf("%c\n",buf[0]);

	pos = lseek(fd,0,SEEK_CUR);
	printf("After reading, the cursor is %d\n",pos);

	r = write(fd,"-",1);
	pos = lseek(fd,0,SEEK_CUR);
	printf("After writing, the cursor is %d\n",pos);

	int fd2 = open("alphabet",O_RDWR|O_APPEND);
	r = write(fd2,"12345678",8);
	pos = lseek(fd,0,SEEK_CUR);
	printf("After another fd writing, the cursor is %d\n",pos);

	r = write(fd,"-",1);
	pos = lseek(fd,0,SEEK_CUR);
	printf("After writing, the cursor is %d\n",pos);
}
