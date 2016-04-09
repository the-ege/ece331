#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[])
{
	struct sysinfo S;
	int status;

	status = sysinfo(&S);
	if(status != 0) {
		perror("sysinfo: ");
		return 1;
	}

	printf("%lu\n", S.loads[1]);

	return 0;
}
