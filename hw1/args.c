#include <stdio.h>

/*
 * This program prints each of the
 * arguments passed to the program
 * on a separate line. This also
 * includes the program name stored
 * in argv[0].
 */

int main(int argc, char *argv[])
{
	int i;
	for (i=0;i<argc;i++) printf("%s\n", argv[i]);
	return 0;
}
