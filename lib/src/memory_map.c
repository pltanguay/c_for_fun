#include <stdio.h>

#include "memory_map.h"

volatile unsigned int fake_reg = 0;

int read_reg_value(volatile unsigned int * reg)
{
    int value = 0;

    if (NULL != reg)
    {
        value = *reg;
    }
    else
    {
        printf("Error: invalid reg\n");
    }

    return value;
}

void write_reg_value(volatile unsigned int * reg, const int value)
{
    if (NULL != reg)
    {
        *reg = value;
    }
    else
    {
        printf("Error: invalid reg\n");
    }
}
