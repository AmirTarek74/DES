/****************************************/
/*          Author: EG TEAM       */        
/*          Date: 14-12-2023            */
/*          Version: 1.0                */
/*          Module: DECRYPTION                 */
/****************************************/

#ifndef SERIAL_H
#define SERIAL_H
#include "StdType.h"
#include <reg51.h>

void display(u32 *arr1, u32* arr2);
void send_value(u8 value);
u8 get_value();
void new_line();

#endif