#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int i, val
	
	if (argc == 2) val=atoi(argv[1]); /* Get the value as an integer */

	/*
	 * Loop over the 31 bits available, mask is 31 bits with a 1 in the MSB pos.
	 * Check to see if the val is divisible by 2^i. If so, a 1 goes there.
	 * Otherwise, it should be a 0. The 2^i computation is taken care of with
	 * the mask. The value is 31 bits with a 1 in MSB (0x8... would give 32 bits).
	 */ 
	for (i=0;i<31;i++) printf("%d", val&(0x80000000>>i)? 1 : 0);

	printf("\n"); /* To keep good terminal formatting */
	return 0;		
}
