/****************************************/
/*          Author: EG TEAM       */        
/*          Date: 14-12-2023            */
/*          Version: 1.0                */
/*          Module: DECRYPTION                 */
/****************************************/
#include "StdType.h"
#include "permutation.h"

void permute(u32* input, u8* arr,u32* initpermute_left,u32* initpermute_right){
    idata u8 i;
		
    for (i = 0; i < 64; i++) {
        if(i<32)
        {
            *initpermute_left <<= 1;
            if(arr[i]>32)
            {
                *initpermute_left |=  (input[1]>> (64 - arr[i])) & LB32_MASK;
            }
            else
            {
                *initpermute_left |=  (input[0]>> (32 - arr[i])) & LB32_MASK;
            }
        }
        else
        {
            *initpermute_right <<= 1;
            if(arr[i]>32)
            {
                *initpermute_right |=  (input[1]>> (64 - arr[i])) & LB32_MASK;
            }
            else
            {
                *initpermute_right |=  (input[0]>> (32 - arr[i])) & LB32_MASK;
            }
        }
        
        }   
}


void KEYpermute(u32* input, u8* arr,u32* initpermute_key_left,u32* initpermute_key_right){
	idata u8 i;
    for (i = 0; i < 56; i++) {
        if(i<28)
        {
            *initpermute_key_left <<=1;
            if(arr[i]>32)
            {
                *initpermute_key_left |= (input[1] >> (64 - arr[i])) &LB32_MASK;
            }
            else
            {
                *initpermute_key_left |= (input[0] >> (32 - arr[i])) &LB32_MASK;
            }
        }
        else
        {
            *initpermute_key_right <<=1;
            if(arr[i]>32)
            {
                *initpermute_key_right |= (input[1] >> (64 - arr[i])) &LB32_MASK;
            }
            else
            {
                *initpermute_key_right |= (input[0] >> (32 - arr[i])) &LB32_MASK;
            }
        }
        }
}
