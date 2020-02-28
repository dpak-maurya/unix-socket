#include <stdlib.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/socket.h>

int main(){
	const char* SOCKNAME="/tmp/mysock";
	struct sockaddr_un *addr;
	int sfd=socket(AF_UNIX,sock_stream,0);
	if (sfd==-1)
	{
		printf("socket creation failed\n");
		exit(0);
	}
	memset(&addr,0,sizeof(struct sockaddr_un));
	addr.sun_family=AF_UNIX;
	strncpy(addr.sun_path,SOCKNAME,sizeof(struct sockaddr_un)-1);
	if(bind(sfd,(struct sockaddr*)&addr,sizeof(sockaddr_un))==-1)
	{
		printf("bind failed\n");
	}
	

}