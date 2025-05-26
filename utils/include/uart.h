#ifndef UART_H
#define UART_H

#include "stdint.h"
#include <stdbool.h>

typedef struct
{
    void (*init)(uint32_t const);
    bool (*tx)(const char *);
    size_t (*rx)(char *, size_t);
} UART;

UART * get_uart(void);
void mock_uart_preload_receive(const char *data);

#endif // UART_H