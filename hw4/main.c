#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "encoder.h"

int main(int argc, char *argv[])
{

	int fd;
	int len;
	char *buffer;

	buffer = malloc(4096);

	if (argc == 3 && !strcmp("-f",argv[1])) {
		/* read from file passed as cmd line arg   */
		/* open() apparently returns -1 on fail... */
		if (open(argv[2],fd,"O_RDONLY") != -1){
			printf("reading...\n");
			len = read(fd,buffer,4096);
			printf("finished reading\n");
		}
		else { //error check on open()
			perror("open:");
			return 1;
		}
		if (len == 0) { //error check on read()
			perror("read:");
			return 1;
		}
		else encode(buffer,len);
		close(fd);
	}
	else if (argc == 2) encode(argv[1],strlen(argv[1])); //passed string on cmd line
	else { //incorrect usage
		printf("Usage: %s -f filename OR %s string\n", argv[0], argv[0]);
		return 1;
	}

	free(buffer);

	return 0;
}
