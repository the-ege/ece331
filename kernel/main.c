#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include "crc.h"
#include "ax25.h"
#include "encoder.h"

#define IOCTL_SET_DELIM 0x70
#define IOCTL_GET_DELIM 0x71

int main(int argc, char* argv[])
{
	int i;						//loop variable
	int fd;						//hold file descriptor of afsk
	uint8_t *buffer;			//holds afsk data to write
	char *msg;					//converted message
	char *callsign;				//ax25 callsign
	char *data_out;				//data to be written
	int size;					//size of the ax25 frame
	int status;					//various error check
	unsigned long *delim;		//hold size of delim in ioctl
	
	/* Error check cmd line args */
	if (argc != 3) {
		fputs("Usage: ./ax25 callsign transmit_data\n",stderr);
		return 1;
	}
	
	callsign = argv[1];
	data_out = argv[2];
	size = strlen(data_out);

	fd = open("/dev/afsk",O_WRONLY);
	/* Error check file open call */
	if (fd == 0) {
		fputs("Cannot open the afsk device!\n",stderr);
		free(buffer);
		free(msg);
		msg = NULL;
		buffer = NULL;
		return 1;
	}

	/* Set delimeter size */
	status=ioctl(fd,IOCTL_SET_DELIM,13);
	status=ioctl(fd,IOCTL_GET_DELIM,delim);

	/* Get the ax25 frame */
	buffer = ax25(callsign,data_out,size);
	if (buffer == NULL) {
		fputs("AX25 failure!\n",stderr);
		return 2;
	}

	/* Set up buffers */
	msg = (char*)malloc(); //These should be the same size

	/* Compare the user space encoding of the frame to kernel space */
	/* Do conversion from uint8_t to char because I'm dumb */
	for (i=0;i<size;i++) {
		msg[i] = (char)buffer[i];
	}
	encode(msg,size,1);

	write(fd,buffer,size);

	close(fd);
	free(buffer);
	free(msg);
	msg = NULL;
	buffer = NULL;
	return 0;
}
