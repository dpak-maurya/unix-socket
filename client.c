#include<stdio.h>
#include <stdlib.h>
#include<sys/un.h>
#include <sys/socket.h>

int main()
{
	const char* SOCKNAME="/tmp/mysock";
	struct sockaddr_un addr;
	int usfd=socket(AF_UNIX,SOCK_STREAM,0);
	memset(&addr,0,sizeof(struct sockaddr_un));
	addr.sun_family=AF_UNIX;
	strncpy(addr.sun_path,SOCKNAME,sizeof(addr.sun_path)-1);

	if(connect(usfd,(struct sockaddr*)&addr,sizeof(struct sockaddr_un))==1){
		printf("connection failed\n");
	}
	char buff[100];
	read(0,buff,100);
	write(usfd,buff,strlen(buff));

	exit(EXIT_SUCCESS);

}