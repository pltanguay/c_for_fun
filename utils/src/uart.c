#include <string.h>
#include <stdio.h>
#include <stddef.h>

#include "uart.h"

#define UART_BUFFER_SIZE 1024

static char tx_buffer[UART_BUFFER_SIZE];
static size_t tx_index = 0;

static char rx_buffer[UART_BUFFER_SIZE];
static size_t rx_index = 0;
static size_t rx_length = 0;

static void uart_init(const uint32_t baudrate)
{
    tx_index = 0;
    rx_index = 0;
    rx_length = 0;

    memset(tx_buffer, 0, sizeof(tx_buffer));
    memset(rx_buffer, 0, sizeof(rx_buffer));
}

static bool uart_send(const char * data)
{
    const size_t length = strlen(data);
    bool success = true;
    if (NULL == data)
    {
        printf("    [MOCK UART SEND] Error: invalid data\n");
        success = false;
    }
    else if ((tx_index + length) > UART_BUFFER_SIZE)
    {
        printf("    [MOCK UART SEND] Error: buffer overflow.\n");
        success = false;
    }
    else
    {
        memcpy(&tx_buffer[tx_index], data, length);
        tx_index += length;
        printf("    [MOCK UART SEND] Success: %.*s\n", (int)length, data);
    }

    return success;
}

static size_t uart_receive(char * buffer, size_t buffer_size)
{
    bool success = true;
    if (NULL == buffer)
    {
        printf("    [MOCK UART RECEIVE] Error: invalid buffer\n");
        success = false;
    }
    else
    {
        size_t available = rx_length - rx_index;
        size_t to_copy = available < buffer_size ? available : buffer_size;
        memcpy(buffer, &rx_buffer[rx_index], to_copy);
        rx_index += to_copy;
        return to_copy;
    }

    return 0;
}

void mock_uart_preload_receive(const char *data)
{
    size_t len = strlen(data);
    if (len < UART_BUFFER_SIZE)
    {
        memcpy(rx_buffer, data, len);
        rx_length = len;
        rx_index = 0;
    }
}

static UART custom_uart =
{
    .init = uart_init,
    .tx   = uart_send,
    .rx   = uart_receive
};

UART * get_uart(void)
{
    return &custom_uart;
}
