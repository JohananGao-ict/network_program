#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <ctype.h>
#include <arpa/inet.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 6666

int main(void){
	
	int cfd;
	struct sockaddr_in serv_addr;
	socklen_t serv_addr_len;
	char buf[BUFSIZ];
	int n;
	
	cfd = socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr);
	
	serv_addr_len = sizeof(serv_addr);
	connect(cfd, (struct sockaddr*)&serv_addr, &serv_addr_len);
	
	while(1){
		fgets(buf, sizeof(buf), stdin);
		write(cfd, buf, strlen(buf));
		n = read(cfd, buf, strlen(buf));
		write(STDOUT_FILENO, buf, n);
	}
	
	close(cfd);
	return 0;
}