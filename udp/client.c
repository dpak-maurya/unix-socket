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
    int sfd;
    struct sockaddr_in serv_addr;
    int port=atoi(argv[1]);
    sfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sfd==-1)
    error("socket creation failed ");

    memset(&serv_addr,'\0',sizeof(struct sockaddr_in));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(port);
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");


    
    char buff[100];
    strcpy(buff,"hello world\n");
    if(sendto(sfd,buff,100,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
    error("send error ");
    printf("+Data send : %s\n",buff);
    
    printf("hii");
    //memset(buff,'\0',sizeof(buff));
    socklen_t serv_size;
    char buff1[100];
    recvfrom(sfd,buff1,100,0,(struct sockaddr*)&serv_addr,&serv_size);
    printf("+Data Received : %s\n",buff1);
    
    return 0;
}