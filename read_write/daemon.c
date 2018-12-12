#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

void dowork(int no){
	time_t curtime;
	//得到当前系统时间
	time(&curtime);
	//格式化时间
	char* pt =ctime(&time);
	int fd = open("/home/kevin/notepad++",O_CREAT|O_WRONLY|O_APPEND,0664);
	write(fd, pt, strlen(pt)+1);
	close(fd);
}

int main(int argc,char* argv[]){
	pid_t pid = fork();
	if(pid>0){
		//父进程退出
		exit(1);	
	}else if(pid == 0){
		//变成会长，脱离控制终端、守护进程
		setsid();
		//改变进程的工作目录
		chdir("/home/kevin");
		//重置掩码
		umask(0);
		//关闭文件描述符
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		//执行核心操作
		// 注册信号捕捉
		//signal()
		struct sigaction act;
		act.sa_flags=0;
		act.sa_handler=dowork;
		sigemptyset(&act.sa_mask);
		sigaction(SIGALRM, &act, NULL);
		//创建定时器
		struct itimerval val;
		//第一次触发的时间
		val.it_value.tv_usec=0;
		val.it_value.tv_sec=0;
		//循环周期
		val.it_interval.tv_usec=0;
		val.it_interval.tv_sec=1;
		setitimer(ITIMER_REAL,&val,NULL);
		
		while(1){  //保证子进程处于运行状态
			
		}
	}
	return 0;
}






