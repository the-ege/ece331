#ifndef AX25
#define AX25
#include <stdint.h>

struct _ax25_t;

/* typedef struct _ax25_t
{
	uint8_t flag1;
	char* addr_dest;
	char* addr_src;
	char* addr_l2ra;
	uint16_t ctrl;
	char* info;
	uint16_t fcs;
	uint8_t flag2;
} ax25_t;
*/
int ax25(char *callsign, char *info);

#endif
