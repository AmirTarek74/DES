/****************************************/
/*          Author: EG TEAM       */        
/*          Date: 14-12-2023            */
/*          Version: 1.0                */
/*          Module: DECRYPTION                 */
/****************************************/

#include "StdType.h"
#include "Utils.h"
#include "BOP.h"
#include "serial.h"
#include <reg51.h>

idata u32 final_perm[2] = {0};

sbit RS = P1^1;
sbit EN =P1^2;

sbit READY = P1^0;
sbit WAIT = P1^1;
u32 X[2] = {0};
u8 msg1[] = "Chiper Text : ";
u8 msg2[] = "Plain Text : ";
u8 counter ;

u8 main(){
	idata u8 i;

		     
    u32 K[2] ={0x75287839,0x7493CB70};
	READY = 0;
	WAIT = 1;
	counter = 0;
	TMOD=0x20;                                //Choosing Timer mode
   	TH1=0xFD;                                   //Selecting Baud Rate
   	SCON=0x50;                               //Serial mode selection
   	TR1=1;
    IE=0x90;                                      //Enabling Serial Interrupt




	CLR_BIT(P1,0);
		while(1)
		{
		 if(counter == 8)
		 {
		 EA = 0;
		 READY = 1;
	   	 WAIT = 0;
		 	for(i=0;i<sizeof(msg1);i++)
			{	
			  	 SBUF =msg1[i];
			  	 while(TI==0);
			 	  TI=0;
			}
		new_line();
		display(&X[0],&X[1]);
		new_line();
		des(X,K,&final_perm[0],&final_perm[1]);
		X[0]=0;
		X[1]=0;
		for(i=0;i<sizeof(msg2);i++)
		{	
			  	 SBUF =msg2[i];
			  	 while(TI==0);
			 	  TI=0;
		}
		 new_line();
		 display(&final_perm[0],&final_perm[1]);
			
		 counter = 0;
			
		  new_line();
		  EA = 1;
		  READY = 0;
		  WAIT = 1;
		} 		
	}
    
    return 0;
}

void ser_intr()interrupt 4        //Subroutine for Interrupt
 {	  
 u8 temp;
  if(RI == 1)
    {	 
		temp = get_value();
		 if(counter<4)
		 {	
		 		X[0] |= ((u32)(temp)<<(3-counter)*8);	
				
		 }
		 else
		 {   
				X[1] |= ((u32)(temp)<<(7-counter)*8);
					
		 }
        RI = 0;              // Clear the Receive interrupt flag
		counter ++;
    }
	else if(TI == 1)
    {
        TI = 0;              // Clear the Transmit interrupt flag
    }
  }