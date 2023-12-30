/****************************************/
/*          Author: EG TEAM       */        
/*          Date: 14-12-2023            */
/*          Version: 1.0                */
/*          Module: DECRYPTION                 */
/****************************************/

#ifndef UTILS_H_
#define UTILS_H_


#define SET_BIT(REG,BIT)  (REG=REG|(1<<BIT))
#define CLR_BIT(REG,BIT)  (REG&=~(1<<BIT))
#define READ_BIT(REG,BIT)  ((REG>>BIT)&1)
#define TOG_BIT(REG,BIT)  (REG=REG^(1<<BIT))
#define WRITE_BIT(REG,BIT,VALUE)  (REG = ((REG &~(1<<BIT)) | (VALUE<<BIT)) )



#endif /* UTILS_H_ */