#include <stdlib.h>
#include<stdio.h>
#include<sys/un.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/socket.h>

int main(){
	const char* SOCKNAME="/tmp/mysock";
	struct sockaddr_un addr;
	int usfd,nusfd;
    usfd=socket(AF_UNIX,SOCK_STREAM,0);
	if (usfd==-1)
	{
		printf("socket creation failed\n");
		exit(0);
	}
	if(remove(SOCKNAME)==-1)
		exit(0);
	memset(&addr,0,sizeof(struct sockaddr_un));
	addr.sun_family=AF_UNIX;
	strncpy(addr.sun_path,SOCKNAME,sizeof(addr.sun_path)-1);
	if(bind(usfd,(struct sockaddr*)&addr,sizeof(struct sockaddr_un))==-1)
	{
		printf("bind failed\n");
	}
	if(listen(usfd,10)==-1)
		printf("listening failed\n");
	while(1){
		nusfd=accept(usfd,NULL,NULL);
		char buff[100];
		int n=read(nusfd,buff,100);
		buff[n]='\0';
		write(1,buff,strlen(buff));
		close(nusfd);
	}



}