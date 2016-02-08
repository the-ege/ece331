#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s int\n", argv[0]);
		return -1;
	}

	int i = atol(argv[1]), j;
	for (j=0;j<i;j++) printf("%x\n",j);

	return 0;
}
