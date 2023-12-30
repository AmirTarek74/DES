#include "main.h"



void init()
{
	counter = 0;    //inital value for incoming bytes number

    /* INDICATIONS LEDS */
	SERIAL_LED = 1;
	READY = 0 ; 
	WAIT = 1 ;
	
	/* serial initlization */
	TMOD=0x20;                               
   	TH1=0xFD;                                   
   	SCON=0x50;                              
   	TR1=1;
    IE=0x90;

}


u8 main(){
	u8 round;		   
	u8 tempByte;	     
    
	init(); 
	                              
	while(1)
		{
		 if(counter == 8)
		 {
		 EA = 0;  			//disable the intterupt
		 READY = 1 ; 		// turn off ready state led
		 WAIT = 0 ;			//	turn on waiting state led

		 des(X,K,&final_perm[0],&final_perm[1]);

		 X[0]=0;
		 X[1]=0;
	
	 for (round=0;round<8;round++)
		{
			if(round<4)
				{
				tempByte = (final_perm[0] >>(3-round)*8 ) & 0xFF;
				send_value(tempByte);
				 
				}
			else
				{
			 	tempByte = (final_perm[1] >>(7-round)*8 ) & 0xFF;
				send_value(tempByte);
				}
			}
			counter = 0;
			EA = 1;
			READY = 0 ; 
			WAIT = 1 ;
		
		} 		
	}
    
    return 0;
}

void ser_intr()interrupt 4        //Subroutine for Interrupt
 {	  
 u8 SBUF_VALUE;
  if(RI == 1)
    {	 
		SBUF_VALUE = get_value();
		 if(counter<4)
		 {	
		 		X[0] |= ((u32)(SBUF_VALUE)<<(3-counter)*8);	
				
		 }
		 else
		 {   
				X[1] |= ((u32)(SBUF_VALUE)<<(7-counter)*8);
					
		 }
        SERIAL_LED = ~SERIAL_LED;
        RI = 0;              // Clear the Receive interrupt flag
		counter ++;
    }
	else if(TI == 1)
    {
        TI = 0;              // Clear the Transmit interrupt flag
    }
  }