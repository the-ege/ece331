#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "crc.h"

uint16_t calcCRC(uint8_t *input, int len)
{

	int i, j;
	uint16_t crcReg = 0xFFFF;
	uint8_t fback;
	uint8_t cbyte, cbit;
	
	for (i=0;i<len;i++) {
		cbyte = input[i]; //get current byte
		
		for (j=0;j<8;j++) {
			cbit = (cbyte & (0x01 << j)) >> j; //get current bit of current byte	

			fback = cbit ^ (crcReg & 0x01); //get the feedback value
			crcReg >>= 1; //perform shifting of the crc, next is setting bits
		

			if (fback == 1) {
				crcReg ^= 0x8408; //reverse crc-16-ccitt polynomial
				crcReg |= 0x8000; //set top bit of crc to 1, fback val

			} else {
				crcReg &= 0x7FFF; //set top bit of crc to 0, fback val

			}
		}
			
	}
	return ~crcReg; //homework asks for 1's compliment

}
