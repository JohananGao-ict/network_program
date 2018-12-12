#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]){
	
	int fd;          //读文件hell.c
	fd = open("hell.c",O_RDONLY); 
	if(fd == -1){
		perror("hell.c open");
		exit(1);
	}
	
	int fd1;           //写文件new.c
	fd1 = open("new.c",O_CREAT|O_WRONLY,0777);
	if(fd1 == -1){
		perror("new.c");
		exit(1);
	}
	
	char buff[1];
	memset(buff,0,sizeof(buff));
	
	int count = read(fd, buff, sizeof(buff));
	if(count == -1){
		perror("read");
		exit(1);
	}
	while(count){
		count = write(fd1, buff, sizeof(buff));
		printf("write beyes %d",count);
		memset(buff,0,sizeof(buff));
		count = read(fd, buff, sizeof(buff));
	}
	
	close(fd);
	close(fd1);
	return 0;
	
	
}






