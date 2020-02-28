#include<sys/stat.h>
#include<sys/uio.h>
#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	struct iovec iov[3];
	char myStruct[15];
	/* First buffer */
	int x;
	/* Second buffer */
	#define STR_SIZE 100
	char str[STR_SIZE];
	/* Third buffer */
	ssize_t numRead, totRequired;
	fd = open(argv[1], O_RDONLY);
	
	totRequired = 0;

	iov[0].iov_base = &myStruct;
	iov[0].iov_len = sizeof(struct stat);
	totRequired += iov[0].iov_len;
	iov[1].iov_base = &x;
	iov[1].iov_len = sizeof(x);
	totRequired += iov[1].iov_len;
	iov[2].iov_base = str;
	iov[2].iov_len = STR_SIZE;
	totRequired += iov[2].iov_len;


	numRead = readv(fd, iov, 3);
	
	if (numRead < totRequired)
	printf("Read fewer bytes than requested\n");
	printf("total bytes requested: %ld; bytes read: %ld\n",
	(long) totRequired, (long) numRead);
	for(int i=0;i<3;i++)
		printf("%s lolo\n",iov[i].iov_base );
	exit(EXIT_SUCCESS);
}