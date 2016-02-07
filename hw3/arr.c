#include <stdio.h>
#include <stdlib.h>

int **setup(int m, int n);

int main(int argc, char *argv[])
{

	/* Check for correct number of args */
	if (argc !=  3) {
		printf("Usage: %s int int\n",argv[0]);
		return 1;
	}

	int m = atoi(argv[1]), n = atoi(argv[2]);
	int **arr = setup(m,n);
	return 0;
}

int **setup(int m, int n)
{
	int i;
	int **x;
	x = (int **)malloc(m*sizeof(int *));
	if (x == NULL) {
		perror("malloc");
		exit(1);
		//keep fixing, free all memory allocated
	}
	for (i=0;i<m;i++) {
		x[i] = (int *)malloc(n*sizeof(int));
		if (x[i] == NULL) {
			perror("malloc 2");
			while (i--) free(x[i]);
			free(x);
			exit(2);
		}
	}

	return x;
}


