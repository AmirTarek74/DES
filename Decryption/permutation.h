/****************************************/
/*          Author: EG TEAM       */        
/*          Date: 14-12-2023            */
/*          Version: 1.0                */
/*          Module: DECRYPTION                 */
/****************************************/

#ifndef PERMUTE_H
#define PERMUTE_H

#define LB32_MASK   0x00000001


void permute(u32* input, u8* arr,u32* initpermute_left,u32* initpermute_right);
void KEYpermute(u32* input, u8* arr,u32* initpermute_key_left,u32* initpermute_key_right);

#endif
