#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encoder.h"

int encode(char *str, int len)
{

	int i,j; //loop counters
	int num; //this value will determine the print
	int stuffCount = 0; //stuffs a 0 when it reaches 5
	int bitCount = 0; //we want to print nicely, even when stuffing bits
	int state = 1; //1->S, 0->M

	for (i=0;i<len;i++) {
		/* Print the binary value LSb first */
		for (j=0;j<8;j++) { //always dealing with 1B of data at a time
			num = str[i] & (0x01 << j);
			if (num != 0) { //the value is "1"
				printf(" 1");
				stuffCount++;

				if (stuffCount == 5) { //see if we need to stuff a 0
					printf(" 0");
					bitCount++; //we've printed another bit
					state = !state;
					stuffCount = 0;
				}

			}
			else { //the value is 0
				printf(" 0");
				stuffCount = 0;
				state = !state;
			}

			bitCount++; //because we've printed a bit
			if (bitCount == 8) {
				printf("\t"); //print formatting
				bitCount = 0;
			}


		}
		

	}
	printf("\n");

	return 0;

}
