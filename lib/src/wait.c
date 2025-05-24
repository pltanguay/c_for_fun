#include "stdio.h"

#include "wait.h"
#include "time.h"

void busy_wait_cycles(const int cycles)
{
    int cyclesLeft = cycles;

    while(cyclesLeft-- > 0)
    {
        __asm__ volatile("nop");
        printf("Tick: %d\n", cyclesLeft);
    }
}

void busy_wait_ms(const int ms)
{
    clock_t start = clock();

    int sec = 0;
    printf("Start: %d\n", sec++);
    while ((((clock() - start) * 1000) / CLOCKS_PER_SEC) < ms)
    {
        __asm__ volatile("nop");
        if ((clock() - start) >= sec * CLOCKS_PER_SEC)
        {
            printf("Sec: %d\n", sec++);
        }
    }
}