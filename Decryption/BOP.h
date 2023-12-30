/****************************************/
/*          Author: EG TEAM       */        
/*          Date: 14-12-2023            */
/*          Version: 1.0                */
/*          Module: DECRYPTION                 */
/****************************************/
#ifndef BOP_H_
#define BOP_H_

#define LB32_MASK   0x00000001
#define L32_MASK    0xffffffff

void des(u32* input, u32* key,u32* final1,u32* final2);

#endif /* BOP_H_ */