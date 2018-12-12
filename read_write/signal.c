#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

int main(int argc,char* argv[]){
	//手动屏蔽信号
	//自定义信号集集合
	sigset_t myset;
	//清空集合
	sigemptyset(&myset);
	//添加要阻塞的信号
	sigaddset(&myset,SIGINT);//ctrl+c
	sigaddset(&myset,SIGQUIT);//ctrl+反斜杠
	sigaddset(&myset,SIGKILL); //ctrl+c
	//自定义集合数据设置给内核的阻塞信号集
	sigprocmask(SIG_BLOCK,&myset,NULL);
	//每隔1s读一次内存的未决信号集
	while(1){
		sigset_t pendset;
		//读取当前进程的未决信号集
		sigpending(&pendset);
		for(int i=1;i<32;i++){
			if(sigismember(&pendset,i)){
				printf("1");
			}
			else{
				printf("0");
			}
		}
		printf("\n");
		sleep(1);	
	}
	return 0;
}






