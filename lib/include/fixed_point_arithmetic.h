#ifndef FIXED_POINT_ARITHMETIC_H
#define FIXED_POINT_ARITHMETIC_H

#include "stdint.h"

/* Format	Bits    Max    Integer	Fractional Bits	Use When…
   -----------------------------------------------------------------------
   Q1.15	16	    ±1	   15	    Need high precision for small numbers
   Q8.8 	16	    ±128   8	    Balance between range & precision
   Q16.16	32	    ±32K   16	    Large range and good precision
*/

float fp_mul_q1_15(const float n1, const float n2);
float fp_mul_q8_8(const float n1, const float n2);
float fp_mul_q16_16(const float n1, const float n2);

#endif // FIXED_POINT_ARITHMETIC_H