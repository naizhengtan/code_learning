#include <stdio.h>
#include <pthread.h>

struct {int a:17; int b:15} x;

void *func(void *p){
	for(int i=0;i<1000000000;i++){
		x.a = 42;
		x.b = 39;
		if(x.a!=42 || x.b!=39){
			printf("x.a %d, x.b %d\n",x.a,x.b);
		}
	}
}

int main(){
	pthread_t threads[10];
	for(int i=0;i<10;i++)
		pthread_create(&threads[i],NULL,func,NULL);

	for(int i=0;i<10;i++)
		pthread_join(threads[i],NULL);

	printf("done\n");
}
