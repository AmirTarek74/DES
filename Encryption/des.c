#include "des.h"
#define LB32_MASK   0x00000001
#define L32_MASK    0xffffffff

void des(u32* input, u32* key)
{
	idata u32 initpermute_key_left,initpermute_key_right,sub_key_left,sub_key_right;
	idata u32 expansaion_left,expansaion_right;
    idata u32 L = 0;
    idata u32 R = 0;
    idata u8 r=0;
    idata u8 c=0;
	idata u8 j;
    idata u8 temp = 0 ;
    idata u32 s_out=0;
    idata u32 s_permute = 0;
	idata u8 iter;
    
	permute(input,IPerm,&L,&R);
    KEYpermute(key,PC1,&initpermute_key_left,&initpermute_key_right);
    
		
    for (iter = 0 ; iter<16;iter++){
	 
			  for (j = 0; j < iteration_shift[iter]; j++)
        	{
	            initpermute_key_left = 0x0fffffff & (initpermute_key_left << 1) | 0x00000001 & (initpermute_key_left >> 27);
	            initpermute_key_right = 0x0fffffff & (initpermute_key_right << 1) | 0x00000001 & (initpermute_key_right >> 27);

        	}
			
			sub_key_left = 0;
			sub_key_right = 0;
				  for(j=0;j<48;j++)
				{
					if(j<24)
					{
							expansaion_left <<=1;
							expansaion_left |= ((R>>(32-E[j])) & LB32_MASK);
							sub_key_left <<= 1;
			               if(PC2[j]>28)
			                    sub_key_left |= (initpermute_key_right >> (56-PC2[j])) & LB32_MASK;
			               else
			                    sub_key_left |= (initpermute_key_left >> (28-PC2[j])) & LB32_MASK;
					}
					else
					{
							expansaion_right <<=1;
							expansaion_right |= ((R>>(32-E[j])) & LB32_MASK);
							sub_key_right <<= 1;
			                if(PC2[j]>28)
			                    sub_key_right |= (initpermute_key_right >> (56-PC2[j])) & LB32_MASK;
			                else
			                    sub_key_right |= (initpermute_key_left >> (28-PC2[j])) & LB32_MASK;
					}
				}
				
     
        for(j = 0;j<8;j++)
        {
            if(j<4)
                temp = ((expansaion_left^sub_key_left)>>(3-j)*6) & 0x3f;   // shift every 6 bits to enter S
            else
                temp = ((expansaion_right^sub_key_right)>>(7-j)*6) & 0x3f;   // shift every 6 bits to enter S

            r = ((temp>>5)<<1) | (temp & 1);    // masking row
            c = (temp>>1) & 0xf;                // getting column
            s_out = (s_out<<4) | S[j][16*r+c];     // output from s box


        }
        for (j = 0 ;j<32;j++)
        {
            s_permute<<=1;
            s_permute |= ((s_out>>(32-Perm[j])) & LB32_MASK);
        }
       
        s_permute= L ^ s_permute;
        L = R;
		R =  s_permute;
    }
    

    for (j = 0; j < 64; j++) {
        if(j<32)
        {
            final_perm[0] <<= 1;
            if(PI[j]>32)
            {
                final_perm[0] |=  (L>> (64 - PI[j])) & LB32_MASK;
            }
            else
            {
                final_perm[0] |=  (R>> (32 - PI[j])) & LB32_MASK;
            }
        }
        else
        {
            final_perm[1] <<= 1;
            if(PI[j]>32)
            {
			
                final_perm[1] |=  (L>> (64 - PI[j])) & LB32_MASK;
            }
            else
            {
                final_perm[1] |=  (R>> (32 - PI[j])) & LB32_MASK;
            }
        }
        }
}