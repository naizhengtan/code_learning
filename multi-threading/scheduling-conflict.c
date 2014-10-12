#include "stdio.h"
#include "pthread.h"

volatile int a=0,b=0;
int c = 0;

void* f1(void* x){
	for(int i=0;i<1000000;i++){
		a = 1;
		b = 1;
		b = 0;
		a = 0;
	}
	return NULL;
}

void* f2(void* sb){
	for(int i=0;i<1000000;i++){
		if(b==1){
			if(a==0) c=1;
		}
	}
	return NULL;
}

int main(){
	pthread_t pthread1,pthread2;
	pthread_create(&pthread1, NULL,f1, NULL);
	pthread_create(&pthread2, NULL, f2, NULL);

	pthread_join(pthread1,NULL);
	pthread_join(pthread2,NULL);
	if(c==1) printf("conflict!\n");
}

