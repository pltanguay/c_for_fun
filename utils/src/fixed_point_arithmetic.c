#include "fixed_point_arithmetic.h"

#include "math.h"
#include "stdio.h"

float fp_mul_q1_15(const float n1, const float n2)
{
    const int N_FRACTIONAL_BITS = 15;

    // Example: 0.5f * 2^15
    int16_t n1_uint = n1 * pow(2, N_FRACTIONAL_BITS);
    int16_t n2_uint = n2 * pow(2, N_FRACTIONAL_BITS);

    // Multiplying two int16_t results in a int32_t type value.
    int32_t temp = (int32_t)n1_uint * (int32_t)n2_uint;

    printf("    Q1.15 fixed-point fractional: %d\n", (int)(temp >> N_FRACTIONAL_BITS));

    return (temp >> N_FRACTIONAL_BITS) / pow(2, N_FRACTIONAL_BITS);
}

float fp_mul_q8_8(const float n1, const float n2)
{
    const int N_FRACTIONAL_BITS = 8;

    // Example: 0.5f * 2^8
    int16_t n1_uint = n1 * pow(2, N_FRACTIONAL_BITS);
    int16_t n2_uint = n2 * pow(2, N_FRACTIONAL_BITS);

    // Multiplying two int16_t results in a int32_t type value.
    int32_t temp = (int32_t)n1_uint * (int32_t)n2_uint;

    printf("    Q8.8 fixed-point fractional: %d\n", (int)(temp >> N_FRACTIONAL_BITS));

    return (temp >> N_FRACTIONAL_BITS) / pow(2, N_FRACTIONAL_BITS);
}

float fp_mul_q16_16(const float n1, const float n2)
{
    const int N_FRACTIONAL_BITS = 16;

    // Example: 0.5f * 2^16
    int32_t n1_uint = n1 * pow(2, N_FRACTIONAL_BITS);
    int32_t n2_uint = n2 * pow(2, N_FRACTIONAL_BITS);

    // Multiplying two int32_t results in a int64_t type value.
    int64_t temp = (int64_t)n1_uint * (int64_t)n2_uint;

    printf("    Q16.16 fixed-point fractional: %d\n", (int)(temp >> N_FRACTIONAL_BITS));

    return (temp >> N_FRACTIONAL_BITS) / pow(2, N_FRACTIONAL_BITS);
}