#ifndef _DES_H
#define _DES_H
#include "StdType.h"
#include "permuation.h"
#include "LOOKUP_TABLES.h"

u32 final_perm[2] = {0};


void des(u32* input, u32* key);

#endif