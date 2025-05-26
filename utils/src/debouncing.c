#include <stdint.h>
#include <stdio.h>

#include "debouncing.h"

#define POLLING_MS    10
#define DEBOUNCING_MS 50

// gpio_read=0   pressed
//          =1   released

void debounce_button(DebounceContext *ctx, const int gpio_read)
{
    if (NULL == ctx)
    {
        printf("Error: invalid context\n");
        return;
    }

    const uint8_t input = gpio_read;

    switch (ctx->state)
    {
    case BUTTON_RELEASED:
        if (0 == input) // Pressed
        {
            ctx->state = BUTTON_DEBOUNCE_PRESS;
            ctx->counter_ms = 0;
        }
        break;
    case BUTTON_DEBOUNCE_PRESS:
        if (0 == input) // Still pressed
        {
            ctx->counter_ms += POLLING_MS;
            if (ctx->counter_ms > 50)
            {
                ctx->state = BUTTON_PRESSED;
                printf("    Button status changed to PRESSED.\n");
            }
        }
        else
        {
            ctx->state = BUTTON_RELEASED;
            printf("    False press. Button is RELEASED.\n");
        }
        break;
    case BUTTON_PRESSED:
        if (1 == input) // Release
        {
            ctx->state = BUTTON_DEBOUNCE_RELEASE;
            ctx->counter_ms = 0;
        }
        break;
    case BUTTON_DEBOUNCE_RELEASE:
        if (1 == input) // Still released
        {
            ctx->counter_ms += POLLING_MS;
            if (ctx->counter_ms > 50)
            {
                ctx->state = BUTTON_RELEASED;
                printf("    Button status changed to RELEASED.\n");
            }
        }
        else
        {
            ctx->state = BUTTON_PRESSED;
            printf("    False release. Button is PRESSED.\n");
        }
        break;
    default:
        break;
    }
}