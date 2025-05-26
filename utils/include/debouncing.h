#ifndef DEBOUNCING_H
#define DEBOUNCING_H

typedef enum
{
    BUTTON_RELEASED,
    BUTTON_DEBOUNCE_PRESS,
    BUTTON_PRESSED,
    BUTTON_DEBOUNCE_RELEASE
} ButtonState;

typedef struct
{
    ButtonState state;
    uint32_t counter_ms;
} DebounceContext;

void debounce_button(DebounceContext *ctx, const int gpio_read);

#endif // DEBOUNCING_H