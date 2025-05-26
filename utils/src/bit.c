#include "bit.h"
#include <stdatomic.h>

unsigned char reverse_byte(const unsigned char byte)
{
    unsigned srcByte = byte;
    unsigned char result = 0x00;

    for (int i = 0; i < 8; i++)
    {
        result <<= 1;
        result |= (srcByte & 1);
        srcByte >>= 1;
    }

    // int shared = 42;
    // int new_val = 100;
    // int old_val;
    //
    // __atomic_exchange(&shared, &new_val, &old_val, __ATOMIC_SEQ_CST);
    // *shared = *new_val

    return result;
}