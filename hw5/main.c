#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "crc.h"

#define BUFFSIZE 4096

int main(int argc, char *argv[])
{

	int fd;
	int len;
	char *buffer;

	if ((argc > 3) || (argc == 1)) {
		printf("Usage: %s -f filename OR %s string\n", argv[0], argv[0]);
		return 1;
	}
	
	/* read from file passed as cmd line arg */
	if ((argc == 3) && (strcmp("-f",argv[1]) == 0)) {
		buffer = (char *)malloc(BUFFSIZE);
		if (buffer == NULL) {
			perror("malloc: ");
			return 2;
		}
		fd = open(argv[2],O_RDONLY);
		if (fd < 0) {
			perror("open:");
			free(buffer);
			buffer = NULL;
			return 3;
		}
		len = read(fd,buffer,BUFFSIZE);
		close(fd);
	} else if (argc == 2) { //Read from cmd line
		buffer = argv[1];
		len = strlen(argv[1]);
	} else { //handles if flag is not -f
		printf("Usage: %s -f filename OR %s string\n", argv[0], argv[0]);
		return 4;
	}
	printf("%.4x\n",calcCRC(buffer,len));
	if (argc == 4) {
		free(buffer);
	}
	buffer = NULL;

	return 0;
}
