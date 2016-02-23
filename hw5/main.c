#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "encoder.h"

#define BUFFSIZE 4096

int main(int argc, char *argv[])
{

	int fd;
	int len;
	int stuffFlag;
	char *buffer;

	if ((argc > 4) || (argc == 1)) {
		printf("Usage: %s -f filename stuffing_enable OR %s string stuffing_enable\n", argv[0], argv[0]);
		return 1;
	}
	
	/* read from file passed as cmd line arg */
	if ((argc == 4) && (strcmp("-f",argv[1]) == 0)) {
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
		stuffFlag = atoi(argv[3]);
		close(fd);
	} else if (argc == 3) { //Read from cmd line
		buffer = argv[1];
		len = strlen(argv[1]);
		stuffFlag = atoi(argv[2]);
	} else { //handles if flag is not -f
		printf("Usage: %s -f filename stuffing_enable OR %s string stuffing_enable\n", argv[0], argv[0]);
		return 4;
	}
	encode(buffer,len,stuffFlag);
	if (argc == 4) {
		free(buffer);
	}
	buffer = NULL;

	return 0;
}
