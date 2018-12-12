#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]){
	
	pid_t pid;
	pid = fork();
	if(pid > 0){
		printf("parent process\n");
	}else if(pid == 0){
		printf("child process\n");
	}else {
		perror("process\n");
		exit(1);
	}
	while(1){
		printf("%d\n",pid);
		//sleep(3);
	}
	
	return 0;
	
	
}






