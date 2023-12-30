#include "serial.h"

void send_value(u8 value)
{
	SBUF = value;	
	while(TI==0);
	TI=0;	
}

u8 get_value()
{	   	
	return SBUF;
}