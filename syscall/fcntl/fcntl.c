#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"

int main(){
	int fd1 = open("_test",O_RDWR|O_CREAT,0777);
	int fd2 = dup(fd1);
	int fd3 = open("_test", O_RDWR);

	int cache_fd_flag = fcntl(fd1,F_GETFD);
	int cache_fl_flag = fcntl(fd1,F_GETFL);

	//Using F_SETFD
	int fd_flag = cache_fd_flag; 
	fd_flag = 
		(fd_flag|FD_CLOEXEC)==fd_flag ? fd_flag&~FD_CLOEXEC : fd_flag|FD_CLOEXEC;
	fcntl(fd1,F_SETFD,fd_flag);

	//Using F_SETFL
	int fl_flag = cache_fl_flag;
	fl_flag = 
		(fl_flag|O_NONBLOCK)==fl_flag ? fl_flag&~O_NONBLOCK: fl_flag|O_NONBLOCK;
	fcntl(fd1,F_SETFL,fl_flag);

	//display
	printf("Orig: %x %x\n",cache_fd_flag,cache_fl_flag);
	printf("fd1: %x %x\n",fcntl(fd1,F_GETFD),fcntl(fd1,F_GETFL));
	printf("fd2: %x %x\n",fcntl(fd2,F_GETFD),fcntl(fd2,F_GETFL));
	printf("fd3: %x %x\n",fcntl(fd3,F_GETFD),fcntl(fd3,F_GETFL));

}

