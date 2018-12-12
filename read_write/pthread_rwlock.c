#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>


int number;
//创建一把读写锁
pthread_mutex_t mutex;

//线程处理函数
void* write_func(void* arg){
	while(1){
		pthread_rwlock_wrlock(&lock);
		number++;
		printf("==write:%lu,%d\n",pthread_self(),number);
		pthread_rwlock_unlock(&lock);
		usleep(500);
	}
	return NULL;
}
void* read_func(void* arg){
	while(1){
		pthread_rwlock_rdlock(&lock);
		printf("==read:%lu,%d\n",pthread_self(),number);
		pthread_rwlock_unlock(&lock);
		usleep(500);
	}
	return NULL;
}

int main(int argc,char* argv[]){
	pthread_t p[8];
	//init读写锁
	pthread_rwlock_init(&lock,NULL);
	//创建3个写线程
	for(int i=0;i<3;i++){
		pthread_create(&p[i],NULL,write_func,NULL);
	}
	//创建5个读线程
	for(int i=3;i<8;i++){
		pthread_create(&p[i],NULL,read_func,NULL);
	}
	//阻塞回收子线程的pcb
	for(int i=0;i<8;i++){
		pthread_join(&p[i],NULL);
	}
	//释放读写锁资源
	pthread_rwlock_destroy(&lock);
	return 0;
}






