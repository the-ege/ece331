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

	int m = atoi(argv[1]), n = atoi(argv[2]), i;
	int **arr = setup(m,n);
	
	/* Freeing memory before exiting */

	for (i=0;i<m;i++) {
		free(arr[i]);
		printf("Slot %d freed\n", i);
	}
	free(arr);
	printf("All memory freed\n");

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
	}
	for (i=0;i<m;i++) {
		x[i] = (int *)malloc(n*sizeof(int));
		if (x[i] == NULL) {
			perror("malloc 2");
			while (i--) {
				free(x[i]);
				printf("Error: MemSlot %d freed\n",i);
			}
			free(x);
			printf("Error: All memory freed\n");
			exit(2);
		}
	}

	return x;
}
