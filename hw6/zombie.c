#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;

	pid = fork(); //pid holds the value of the child process
	if (pid < 0) { //fail on fork
		perror("fail on fork: ");
		return 1;
	} else if (pid == 0) { //the child running the code thinks it has pid 0
		while(1) {
			sleep(1); //sleep for one second
		}
	} else { //parent process
		kill(pid,SIGKILL);
		sleep(10);	
	}

	return 0;
}
