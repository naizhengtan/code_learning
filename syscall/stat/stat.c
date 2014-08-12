#include "sys/stat.h"
#include "stdio.h"

int main(int args, char *argv[]){
	if(args<2){
		printf("Usage: give a file name as parameter\n");
		return 1;
	}

	struct stat f_stat;
	int r = lstat(argv[1],&f_stat);
	if(r==-1){
		perror("stat:");
		return 2;
	}

	if(S_ISREG(f_stat.st_mode)){
		printf("regular file\n");
	}else if(S_ISDIR(f_stat.st_mode)){
		printf("dir file\n");
	}else if(S_ISCHR(f_stat.st_mode)){
		printf("char device\n");
	}else if(S_ISBLK(f_stat.st_mode)){
		printf("block device\n");
	}else if(S_ISFIFO(f_stat.st_mode)){
		printf("fifo\n");
	}else if(S_ISLNK(f_stat.st_mode)){
		printf("link file\n");
	}else if(S_ISSOCK(f_stat.st_mode)){
		printf("socket\n");
	}else{
		printf("Unkown\n");
	}

	//st_size is good for reg/link/dir
	int size = f_stat.st_size;
	printf("size is %d\n",size);
}
