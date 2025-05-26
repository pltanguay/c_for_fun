#ifndef BIT_H
#define BIT_H

#define BIT_SET(REG, BIT) (REG |= (1U << BIT))
#define BIT_CLEAR(REG, BIT) (REG &= ~(1U << BIT))
#define BIT_TOGGLE(REG, BIT) (REG ^= (1U << BIT))

unsigned char reverse_byte(const unsigned char byte);

#endif // BIT_H