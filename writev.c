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

	iov[0].iov_base = buf0;
	iov[0].iov_len = strlen(buf0);
	iov[1].iov_base = buf1;
	iov[1].iov_len = strlen(buf1);
	iov[2].iov_base = buf2;
	iov[2].iov_len = strlen(buf2);

	iovcnt = sizeof(iov) / sizeof(struct iovec);

	bytes_written = writev(fd, iov, iovcnt);
}