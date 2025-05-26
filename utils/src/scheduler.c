#include <stdint.h>

#include "scheduler.h"


volatile uint32_t tick_ms = 0;

void sys_tick_handler(void)
{
    tick_ms++;
}

static void task_ms1()
{
    // implement something here
    return;
}

static void task_ms10()
{
    // implement something here
    return;
}

static void task_ms100()
{
    // implement something here
}

void scheduler_loop(void)
{
    static uint32_t last1 = 0;
    static uint32_t last10 = 0;
    static uint32_t last100 = 0;

    while (0 /*1*/)
    {
        // 1 ms
        if (tick_ms - last1 > 1)
        {
            last1 = tick_ms;
            task_ms1();
        }

        // 10 ms
        if (tick_ms - last10 > 10)
        {
            last10 = tick_ms;
            task_ms10();
        }

        // 100 ms
        if (tick_ms - last100 > 100)
        {
            last100 = tick_ms;
            task_ms100();
        }
    }
}