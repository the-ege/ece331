#include <stdio.h>
#include <glob.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	glob_t glob_struct;
	struct stat stat_struct;
	int status, i;

	if (argc == 1 || argc > 2){ /* There is always at least one argument, the program name */
		printf("Incorrect number of arguments!\n");
		return -1;
	}
	
	status = glob(argv[1], 0, NULL, &glob_struct);
	
	/* Error checking */

	if (status == GLOB_NOSPACE) {
		printf("Glob returns out of memory error!\n");
		return -2;
	}
	else if (status == GLOB_ABORTED) {
		printf("Glob returns a read error!\n");
		return -3;
	}
	else if (status == GLOB_NOMATCH) {
		printf("Glob returns no found matches!\n");
		return -4;
	}

	i = glob_struct.gl_offs;

	return 0;

	for (i=0;i<glob_struct->gl_offs;i++) {
		status = stat(glob_struct->gl_pathv[i], &stat_struct); /* Call stat() on glob path, get info back*/
		/* Error checking */

		if (status != 0) {
			printf("Stat returns an error!\n");
			return -5;
		}

		/* Print permissions in hex */

		printf("0x%04x\n", stat_struct.st_mode);

	}	

	globfree(&glob_struct); /* Pre-written function to free dynamically allocated mem in glob struct */

	return 0;
}
