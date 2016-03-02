#include <stdio.h>
#include "crc.h"
#include "ax25.h"

int main(int argc, char* argv[])
{
	int status;
	if (argc != 3) {
		fputs("Usage: ./ax25 callsign transmit_data\n",stderr);
		return 1;
	}
	
	status = ax25(argv[1],argv[2]);
	if (status != 0) {
		fputs("Error!\n",stderr);
		return 2;
	}
	return 0;
}
