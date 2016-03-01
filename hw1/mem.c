#include <stdio.h>
#include <stdlib.h>

/*
 * The last line that is printed to stdout is the last
 * successful amount of bytes that can be allocated. It
 * is possible that some number of bytes between the
 * printed value and twice that value can be allocated.
 */

int main(void)
{
	size_t i = 1;
	void *ptr;

	while (1) {
		ptr = malloc(i);
		if (ptr != NULL) free(ptr); /* Frees only if allocation is successful */
		else return 0;
		printf("Allocated %d bytes\n", i);
		i *= 2;

	}
}
