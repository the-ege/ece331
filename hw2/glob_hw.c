#include <stdio.h>
#include <glob.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*
 * Program takes one command line argument as a glob pattern
 * and returns the file permissions as hex for each file
 * matched with the glob pattern.
 */

int main (int argc, char *argv[])
{
	glob_t glob_struct;
	struct stat stat_struct;
	int status, i;

	if (argc == 1 || argc > 2) { /* There is always at least one argument, the program name */
		printf("Incorrect number of arguments!\n");
		return -1;
	}
	
	status = glob(argv[1], 0, NULL, &glob_struct);
	
	/* Error checking */

	if (status == GLOB_NOSPACE) {
		printf("Glob returns out of memory error!\n");
		globfree(&glob_struct);
		return -2;
	}
	else if (status == GLOB_ABORTED) {
		printf("Glob returns a read error!\n");
		globfree(&glob_struct);
		return -3;
	}
	else if (status == GLOB_NOMATCH) {
		printf("Glob returns no found matches!\n");
		globfree(&glob_struct);
		return -4;
	}

	for (i=0;i<glob_struct.gl_pathc;i++) {
		status = stat(glob_struct.gl_pathv[i], &stat_struct); /* Call stat() on glob path, get info back*/
		/* Error checking */

		if (status != 0) {
			printf("Stat returns an error!\n");
			globfree(&glob_struct);
			return -5;
		}

		/* Print permissions in hex */

		printf("%s : 0x%04x\n", glob_struct.gl_pathv[i],stat_struct.st_mode);

	}	

	globfree(&glob_struct); /* Pre-written function to free dynamically allocated mem in glob struct */

	return 0;
}
