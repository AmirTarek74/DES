#ifndef MAIN_H
#define MAIN_H

#include "des_enc.h"
#include "serial.h"


sbit SERIAL_LED = P1^0;
sbit READY = P1^1;
sbit WAIT = P1^2;

u32 final_perm[2] = {0};					 // to save final results from des function after encryption 

u32 X[2] = {0};								// Plain text array to save values from SBUF

u32 K[2] ={0x75287839,0x7493CB70};  			  // the key

u8 counter ;
  


void init();

#endif