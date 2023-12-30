/****************************************/
/*          Author: EG TEAM       */        
/*          Date: 14-12-2023            */
/*          Version: 1.0                */
/*          Module: DECRYPTION                 */
/****************************************/

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

void display(u32 *arr1, u32* arr2)
{
u8 i,temp;
	 for (i=0;i<8;i++)
		{
			if(i<4)
				{
				temp = (*arr1 >>(3-i)*8 ) & 0xFF;
				send_value(temp);
				 
				}
			else
				{
			 	temp = (*arr2 >>(7-i)*8 ) & 0xFF;
				send_value(temp);
				}
			}	
}
void new_line()
{
			SBUF ='\r';
			while(TI==0);
			TI=0;
			SBUF ='\n';
			while(TI==0);
			TI=0;
}