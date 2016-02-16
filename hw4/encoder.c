#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encoder.h"

void encode(char *str){

	int i,j,num;

	for (i=0;i<strlen(str);i++) {
		num = atoi(str[i]);
		/* Print the binary value LSb first */
		for (j=0;j<8;j++) { //always dealing with 1B of data at a time
			printf(" %d",num&(0b00000001 << j)? 1 : 0);
		}
		printf("\t");
	}
	printf("\n");

}
