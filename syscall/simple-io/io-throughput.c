#include "stdio.h"
#include "sys/time.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"

#define FILE_SIZE (4096*4096*10)
#define METH_NUM (3)
#define BUFFER (512)

char* prepareContent(int size){
	char* buffer = malloc(size);	
	srandomdev();
	int i=0;
	for(i=0;i<size;i++){
		buffer[i] = random()%128;
	}
	return buffer;
}

void writeNosyncNobuffer(const char* content, int size, const char* name){
	int fd = open(name,O_RDWR|O_CREAT|O_TRUNC);
	int total = 0;
	do{
		int tmp = write(fd,content,BUFFER);

		if(tmp==-1){
			perror("No Sync No Buffer:");
			return;
		}

		total += tmp;
	}while(total<size);
	close(fd);
}


void writeSyncNobuffer(const char* content, int size, const char* name){
	int fd = open(name,O_RDWR|O_CREAT|O_TRUNC|O_SYNC);
	int total = 0;
	do{
		int tmp = write(fd,content,BUFFER);

		if(tmp==-1){
			perror("Sync No Buffer:");
			return;
		}

		total += tmp;
	}while(total<size);
	close(fd);
}

void writeSyncCmd(const char* content, int size, const char* name){
	int fd = open(name,O_RDWR|O_CREAT|O_TRUNC);
	int total = 0;
	do{
		int tmp = write(fd,content,BUFFER);

		if(tmp==-1){
			perror("Sync Cmd No Buffer:");
			return;
		}
		fsync(fd);
		total += tmp;
	}while(total<size);
	close(fd);
}


int main(int args, char* argv[]){

	char* path = argv[1];

	struct timeval start,end;
	int millisec;

	char* content = prepareContent(FILE_SIZE);//10M

	//trying to prevent warmup problem
	void (*fp[])(const char* ,int, const char*) = {
		writeNosyncNobuffer,
		writeSyncNobuffer,
		writeSyncCmd
	};

	char* title[] = {
		"No Sync No Buffer",
		"Sync No Buffer",
		"Sync Cmd"
	};

	//no sync, buffered

	int counter = 0;
	int blur = random()%METH_NUM;
	//no sync, no buffered 
	do{
		//FIXME: do not care error now
		gettimeofday(&start,NULL);

		char name[20];
		sprintf(name, "_test%d",counter);
		fp[blur%3](content,FILE_SIZE,name);

		gettimeofday(&end,NULL);
		millisec = (end.tv_sec - start.tv_sec)*1000 + (end.tv_usec - start.tv_usec)/1000;
		printf("%s: %d ms\n",title[blur%3],millisec);

		counter++;
		blur++;
	}while(counter<3);

}
