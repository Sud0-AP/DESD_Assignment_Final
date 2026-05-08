#include <stdio.h>
#include <sys/types.h>    
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define SERVER_IP "192.168.83.210"
#define SERVER_PORT 5050

volatile int client_fd;

void *t_send(void *);
void *t_receive(void *);

int main(){

	pthread_t sender, receiver;

	struct sockaddr_in server_addr;		//struct sockaddr_in {
	int ret;			//sa_family_t    sin_family; // address family: AF_INET 
	char buffer[512] = {0}; 	       	//in_port_t      sin_port;   // port in network byte order 
       					        //struct in_addr sin_addr;   // internet address 
       						//};

	client_fd = socket(AF_INET, SOCK_STREAM, 0); //int socket(int domain, int type, int protocol);  SOCK_STREAM -> TCP, SOCK_DGRAM -> UDP, SOCK_RAW RAW. 
	if(client_fd == -1){
		perror("Create error:");
		return 0;
	}
	
	printf("Client FD: %d created\n", client_fd);

	server_addr.sin_family = AF_INET;

	server_addr.sin_port = htons(SERVER_PORT); //uint16_t htons(uint16_t hostshort); function converts the unsigned short integer hostshort from host byte order to network byte order.
						   
	ret = inet_pton(AF_INET, SERVER_IP, (void *) &server_addr.sin_addr); // int inet_pton(int af, const char *src, void *dst);  This function converts the character string src into a network address structure in the af address family, then copies the network address structure to dst. 

	if(ret != 1){
		perror("inet_pton error:");
		close(client_fd);
		return 0;
	}

	printf("server ip configured!!\n");
	ret = connect(client_fd, (const struct sockaddr *) &server_addr, sizeof(struct sockaddr)); //int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);  The  connect()  system  call connects the socket referred to by the file descriptor sockfd to the address specified by addr.  The addrlen argument specifies the size of addr. 

	if(ret == -1){
		perror("Error connecting to server: ");
		close(client_fd);
		return 0;
	}

	printf("Connected to server !!\n");

	ret = pthread_create(&sender, NULL, t_send, NULL);
	if(ret != 0){
		printf("Error: ");
		close(client_fd);
		return 0;
	}

	ret = pthread_create(&receiver, NULL, t_receive, NULL);
	if(ret != 0){
		printf("Error: ");
		close(client_fd);
		return 0;
	}

	
	ret = pthread_join(receiver, NULL);
	if(ret != 0){
		printf("Error: ");
		close(client_fd);
		return 0;
	}
	
	ret = pthread_join(sender, NULL);
	if(ret != 0){
		printf("Error: ");
		close(client_fd);
		return 0;
	}

	close(client_fd);
	return 0;
}
void *t_send(void *arg){
	char str[512] = {0};
	int ret;

	while(1){
		read(0, str, sizeof(str));
		strcat(str, "\n");

		ret = send(client_fd ,(void *) str , strlen(str), 0);
		if(ret <= 0){
			perror("S Connection closed : ");
			close(client_fd);
			return 0;
		}
		memset(str, 0, strlen(str));
		printf("\n");
	}

	pthread_exit(NULL);
}
void *t_receive(void *arg){
	char buffer[512] = {0};
	int ret;
	while(1){
		memset(buffer, 0, strlen(buffer));
		ret = recv(client_fd, (void *) buffer, sizeof(buffer), 0);
		if(ret <= 0){
			perror("R Connection closed : ");
			close(client_fd);
			return 0;
		}

		printf("\nRecived string: %s\n", buffer);
	}

	pthread_exit(NULL);
}
