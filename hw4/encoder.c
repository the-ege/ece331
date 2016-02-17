#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encoder.h"

int encode(char *str, int len){

	int i,j; //loop counters
	int num; //this value will determine the print
	int stuffCount = 0; //stuffs a 0 when it reaches 5
	int bitCount = 0; //we want to print nicely, even when stuffing bits
	int state = 1;

	for (i=0;i<len;i++) {
		/* Print the binary value LSb first */
		for (j=0;j<8;j++) { //always dealing with 1B of data at a time
			num = str[i] & (0x01 << j);
			if (num != 0) { //no need to make it a 0 or 1, we know it's a 1
				printf(" 1");
				stuffCount++;
				if (stuffCount == 5) {
					printf(" 0");
					bitCount++;
					state = !state;
					stuffCount = 0;
				}
			}
			else { //our value is 0
				printf(" 0");
				stuffCount = 0;
				state = !state;
			}
			
			bitCount++;
			if (bitCount == 8) {
				printf("\t");
				bitCount = 0;
			}

		}

	}
	printf("\n");

	return 0;

}
