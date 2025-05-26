#include "bit.h"

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

    return result;
}