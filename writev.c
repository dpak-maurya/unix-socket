#include<sys/stat.h>
#include<sys/uio.h>
#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char *argv[])
{
	ssize_t bytes_written;
	int fd;
	char *buf0 = "short string\n";
	char *buf1 = "This is a longer string\n";
	char *buf2 = "This is the longest string in this example\n";
	int iovcnt;
	struct iovec iov[3];
<<<<<<< HEAD

	iov[0].iov_base = buf0;
	iov[0].iov_len = strlen(buf0);
	iov[1].iov_base = buf1;
	iov[1].iov_len = strlen(buf1);
	iov[2].iov_base = buf2;
	iov[2].iov_len = strlen(buf2);
=======
	char myStruct[]="this is cn lab .writing code for writev.";	/* First buffer */
	char x='1';
	/* Second buffer */
	#define STR_SIZE 100
	char str[]="today thsi dfslkj fdaskljf afds  fadsklj adfs\n";
	/* Third buffer */
	ssize_t numWrite, totRequired;
	fd = open(argv[1], O_WRONLY|O_CREAT);
	
	totRequired = 0;

	iov[0].iov_base = myStruct;
	iov[0].iov_len = sizeof(myStruct);
	totRequired += iov[0].iov_len;
	iov[1].iov_base = &x;
	iov[1].iov_len = sizeof(x);
	totRequired += iov[1].iov_len;
	iov[2].iov_base = str;
	iov[2].iov_len = strlen(str);
	totRequired += iov[2].iov_len;
>>>>>>> Readv

	iovcnt = sizeof(iov) / sizeof(struct iovec);

<<<<<<< HEAD
	bytes_written = writev(fd, iov, iovcnt);
=======
	numWrite = writev(fd, iov, 3);
	
	if (numWrite < totRequired)
	printf("write fewer bytes than requested\n");
	printf("total bytes requested: %ld; bytes write: %ld\n",
	(long) totRequired, (long) numWrite);
	for(int i=0;i<3;i++)
		printf("%s\n",(char*)iov[i].iov_base );
	exit(EXIT_SUCCESS);
>>>>>>> Readv
}