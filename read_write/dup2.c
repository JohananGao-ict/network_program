#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]){
	
	int fd = open("hell.c",O_RDWR);
	int fd1 ;
	//int fd1 = open("dup2.c",O_RDWR);;
	//int ret = dup2(fd,fd1);
	int ret = dup2(fd,fd1);
	//int ret = dup(fd);
	printf("fd=%d\n",fd);
	printf("fd1=%d\n",fd1);
	printf("ret=%d\n",ret);
	
	
	close(fd);
	close(fd1);
	
	return 0;
	
	
}






