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

void* myfunc(void* arg){
	//打印子线程的id
	printf("child thread id:%lu\n", pthread_self());
	pthread_exit(NULL);
	
}

int main(int argc,char* argv[]){
	//创建一个子线程
	//线程ID变量
	pthread_t pthid;
	//创建线程的时候设置线程分离
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_create(&pthid, &attr, myfunc, NULL);
	printf("parent thread id:%lu\n", pthread_self());
	//阻塞等待子线程退出，并且回收起pcb
	//pthread_join(pthid,NULL);
	for(int i=0l; i<5;++i){
		printf("i=%d\n",i);
	}
	sleep(2);
	//释放资源
	pthread_attr_destroy(&attr);
	return 0;
}






