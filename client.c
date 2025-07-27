ï»¿/* simpleChatClient.c */
#include "headers.h"
#include "stdio.h"
void handlerSend(int num)
{
	int status;
	wait(&status);
	puts("Sending Child exited");
}

int main(int argc,char **argv)
{
	signal(SIGCHLD,handlerSend);
	int fd;
	struct sockaddr_in addr;
	if(argc<3)
	{  
		puts("input:./client(exe) server_port server_ip\n"); exit(0);  
	}

	puts("creating client socket\n");
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		perror("socket");
		exit(0);
	}
	puts("client socket created succussfully\n");

	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr(argv[2]);
	addr.sin_port=htons(atoi(argv[1]));

	puts("connecting with server ....\n");
	socklen_t len=sizeof(addr);

	if(connect(fd,(const struct sockaddr *)&addr,len)<0)
	{ 
		perror("connect"); exit(0); 
	}
	puts("connected with server\n");

	char buff[100]; int pid;

	if((pid=fork())==0)
	{
		//  write code here for CLIENT CHILD
		//  alwayts use to send MSG to server
	//  ( can not send directly to another client so sending to server and server will send to another client )
	}
	else
	{
		//write code here for CLIENT PARENT
		//always use to recv MSG from server and will print on screen
	//  ( can not recv directly from another client. So, another client sending to server and server will send to this client )
	
	}
}


/*end of simpleChatClient.c */
