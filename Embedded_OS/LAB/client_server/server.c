#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <sys/types.h> 
#include <errno.h>
#include <unistd.h>

#define BIND_PORT 5050

int main(){
	int list_fd, ret, opt, con_fd;
	struct sockaddr_in bind_addr;

	list_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(list_fd == -1){
		perror("Socket creation : ");
		return 0;
	}
	printf("Server Socket: %d\n", list_fd);

	opt = 1;
//	ret = setsockopt(list_fd, SOL_SOCKET, SO_REUSEADDR, (const void *) &opt, sizeof(opt));
	if(ret == -1){
		perror("setsockopt: ");
		close(list_fd);
		return 0;
	}
	printf("REUSEASSR opt set\n");

	bind_addr.sin_family = AF_INET;
	bind_addr.sin_port = htons(BIND_PORT);
	bind_addr.sin_addr.s_addr = INADDR_ANY;
	ret = bind(list_fd, (const struct sockaddr *) &bind_addr, sizeof(struct sockaddr));
	if(ret == -1){
		perror("sock bind err: ");
		close(list_fd);
		return 0;
	}
	printf("List FD: %d bind success\n", list_fd);

	ret = listen(list_fd, 0);
	if(ret == -1){
		perror("Listen error: ");
		close(list_fd);
		return 0;
	}
	printf("List FD: %d listen success\n", list_fd);

	printf("Server will now wait for incoming connection...\n");

	while(1){
		con_fd = accept(list_fd, NULL, NULL);
		if(con_fd == -1){
			perror("Accept error: ");
			close(list_fd);
			return 0;
		}
		printf("Accept success, con_fd = %d\n", con_fd);
		
		char buff[512] = {0};
		ret = recv(con_fd, (void *)buff, sizeof(buff), 0);
		if(ret <= 0){
			perror("Connection closed: ");
			close(list_fd);
			close(con_fd);
			return 0;
		}
		printf("con_fd: %d, received: %d bytes\n", con_fd, ret);
		printf("Recived string %s\n", buff);

		ret = send(con_fd, (const void *)"Hello from server", 17, 0);
		if(ret <= 0){
			perror("Connection closed: ");
			close(list_fd);
			close(con_fd);
			return 0;
		}
		printf("con_fd: %d, send: %d bytes\n", con_fd, ret);
		close(con_fd);
	}
	close(list_fd);
	return 0;
}
