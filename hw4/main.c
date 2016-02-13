#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s, filename\n", argv[0]);
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");
	if (fp == NULL) {
		perror("fopen: ");
		return 1;
	}
	fclose(fp);
	return 0;
}
