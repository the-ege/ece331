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

int main(int argc, char* argv[])
{
	int status;					//holds status of function calls
	int fd;						//hold file descriptor of afsk
	uint8_t *buffer;			//holds afsk data to write
	char *callsign;				//ax25 callsign
	char *data_out;				//data to be written
	int size;					//size of the ax25 frame
	
	
	/* Error check cmd line args */
	if (argc != 3) {
		fputs("Usage: ./ax25 callsign transmit_data\n",stderr);
		return 1;
	}
	
	callsign = argv[1];
	data_out = argv[2];
	size = strlen(data_out);

	buffer = ax25(callsign,data_out,size);
	if (buffer == NULL) {
		fputs("AX25 failure!\n",stderr);
		return 2;
	}

	fd = open("/dev/afsk",O_WRONLY);
	/* Error check file open call */
	if (fd == 0) {
		fputs("Cannot open the afsk device!\n",stderr);
		return 1;
	}

	write(fd,buffer,size);

	close(fd);
	return 0;
}
