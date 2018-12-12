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

#define MAX 10000  
//全局变量  输出1-20000，因为两个线程各是10000
int number;
//创建一把互斥锁
pthread_mutex_t mutex;

//线程处理函数
void* funcA_num(void* arg){
	for(int i=0;i<MAX;i++){
		//访问全局变量之前加锁
		//如果mutex被锁上了，代码阻塞在当前位置
		pthread_mutex_lock(&mutex);
		int cur=number;
		cur++;
		number=cur;
		printf("Thread A,id=%lu,number=%d\n",pthread_self(),number);
		//解锁
		pthread_mutex_unlock(&mutex);
		usleep(10);
	}
	return NULL;
}
void* funcB_num(void* arg){
	for(int i=0;i<MAX;i++){
		pthread_mutex_lock(&mutex);
		int cur=number;
		cur++;
		number=cur;
		printf("Thread B,id=%lu,number=%d\n",pthread_self(),number);
		pthread_mutex_unlock(&mutex);
		usleep(10);
	}
	return NULL;
}

int main(int argc,char* argv[]){
	pthread_t p1,p2;
	//初始化互斥锁
	pthread_mutex_init(&mutex,NULL);
	//创建两个子线程
	pthread_create(&p1,NULL,funcA_num,NULL);
	pthread_create(&p2,NULL,funcB_num,NULL);
	//阻塞，资源回收
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	//释放互斥锁资源
	pthread_mutex_destroy(&mutex);
	return 0;
}






