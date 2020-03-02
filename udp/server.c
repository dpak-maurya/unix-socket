#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void error(char *s)
{
    perror(s);
    exit(0);
}

int main(int argc,char **argv){
    int sfd,nsfd;
    struct sockaddr_in serv_addr,cli_addr;
    int port=atoi(argv[1]);
    sfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sfd==-1)
    error("socket creation failed ");
    memset(&serv_addr,'\0',sizeof(struct sockaddr_in));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(port);
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(bind(sfd,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr_in))==-1)
    error("socket bind failed " );
    else printf("socket bind to port %d\n",port);

    socklen_t cli_size;
    char buff[100];
    recvfrom(sfd,buff,100,0,(struct sockaddr*)&cli_addr,&cli_size);
    printf("+Data Received : %s\n",buff);
    
    memset(buff,'\0',sizeof(buff));

    strcpy(buff,"hello world from server\n");
    if(sendto(sfd,buff,100,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
    error("send error ");
    printf("+Data send : %s\n",buff);
    return 0;
}