#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "hello.h"
#include "allocate.h"
#include "bit.h"
#include "wait.h"
#include "memory_map.h"
#include "circular_buffer.h"
#include "fixed_point_arithmetic.h"

bool say_hi(const char * name, const size_t size, bool (*func)(const char *, const size_t))
{
    return func(name, size);
}

int main(int argc, char *argv[])
{
    if (2 == argc)
    {
        const int len = strlen(argv[1]);
        const char * name = argv[1];

        // Char buffer
        if (say_hi(name, len, say_hello))
        {
            printf("Done: funcHello()\n\n");
        }
        else
        {
            printf("Error: failed funcHello()\n");
        }

        // Allocate
        const int rows = 4;
        const int cols = 12;
        int **array = allocate_2d(rows, cols);

        array[1][2] = 42;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }

        free_2d(array, 4);
        printf("Done: allocate_2d() and free_2d()\n\n");

        // Bit
        uint32_t reg = 0x0;

        BIT_SET(reg, 3);
        printf("Value: %d\n", reg);

        BIT_CLEAR(reg, 3);
        printf("Value: %d\n", reg);

        BIT_TOGGLE(reg, 3);
        printf("Value: %d\n", reg);

        BIT_TOGGLE(reg, 3);
        printf("Value: %d\n", reg);

        printf("Done: Bit\n\n");

        // Wait
        busy_wait_cycles(10);
        printf("Success: busy_wait_cycles\n\n");

        busy_wait_ms(2000);
        printf("Success: busy_wait_ms\n");

        printf("Done: Wait\n\n");

        // Memory map
        printf("Start. Value REG_ADDRESS: %d\n", *REG_ADDRESS);

        write_reg_value(REG_ADDRESS, 64);
        printf("write_reg_value. Value REG_ADDRESS: %d\n", *REG_ADDRESS);

        const int ret = read_reg_value(REG_ADDRESS);
        printf("read_reg_value. Value REG_ADDRESS: %d\n", *REG_ADDRESS);
        printf("read_reg_value. Value ret: %d\n", ret);

        printf("Done: Memory map\n\n");

        // Circular buffer
        CircularBuffer cb;

        printf("CircularBuffer: cb_init()\n");
        cb_init(&cb);
        cb_print(&cb);

        printf("CircularBuffer: cb_pop()\n");
        cb_pop(&cb); // expecting warning
        cb_print(&cb);

        printf("CircularBuffer: filling buffer\n");
        for (int i = 0; i < CB_SIZE; i++)
        {
            cb_push(&cb, i * 10);
        }
        cb_print(&cb);

        printf("CircularBuffer: cb_push() when full\n");
        cb_push(&cb, 99); // expecting warning
        cb_print(&cb);

        printf("CircularBuffer: emptying buffer\n");
        for (int i = 0; i < CB_SIZE; i++)
        {
            const int popped = cb_pop(&cb);
            printf("    Popped value: %d\n", popped);
        }
        cb_print(&cb);

        printf("Done: Circular buffer\n\n");

        // Fixed-point arithmetic
        const float f1 = 0.75f;
        const float f2 = -0.025;

        printf("Multiplying '%f' to '%f':\n", f1, f2);
        float result = fp_mul_q1_15(f1, f2);
        printf("Float value Q1.15: %f\n", result);

        result = fp_mul_q8_8(f1, f2);
        printf("Float value Q8.8: %f\n", result);

        result = fp_mul_q16_16(f1, f2);
        printf("    Float value Q16.16: %f\n", result);

        printf("Done: Fixed-point arithmetic\n\n");
    }
    else
    {
        printf("Error: Wrong number of argument : %d\n", argc);
        return 1;
    }

    printf("\nBYE!\n");

    return 0;
}