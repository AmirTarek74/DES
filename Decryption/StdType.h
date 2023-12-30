/****************************************/
/*          Author: EG TEAM       */        
/*          Date: 14-12-2023            */
/*          Version: 1.0                */
/*          Module: DECRYPTION                 */
/****************************************/
#ifndef TYPES_H_
#define TYPES_H_

#define NULLPTR ((void *)0)

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;



typedef unsigned long u32;
typedef signed long s32;


typedef enum{
	OK,
	NOK,
	NULL_PTR,
	OUT_OF_RANG,
}ERROR_TYPE;

typedef enum{
	FALSE,
	TRUE
}BOOL_TYPE;




#endif /* TYPES_H_ */