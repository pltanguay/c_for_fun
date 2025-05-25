#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include "stdint.h"


// That's what I would use on an embedded device to set an actual real register, but will "fake" it just for fun!
// #define REG_ADDRESS ((volatile unsigned int *)0x40021000)
extern volatile unsigned int fake_reg;
#define REG_ADDRESS (&fake_reg)

int read_reg_value(volatile unsigned int * reg);
void write_reg_value(volatile unsigned int * reg, const int value);


#endif // MEMORY_MAP_H