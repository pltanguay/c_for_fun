#include <stdio.h>
#include <stdbool.h>

#include "circular_buffer.h"

void cb_init(CircularBuffer* cb)
{
    if (NULL != cb)
    {
        cb->tail = 0;
        cb->head = 0;
        cb->count = 0;
    }
    else
    {
        printf("Error: invalid cb.\n");
    }
}

void cb_push(CircularBuffer* cb, const int value)
{
    if (NULL != cb)
    {
        if (!cb_is_full(cb))
        {
            cb->buffer[cb->head] = value;
            cb->head = (cb->head + 1) % CB_SIZE;
            cb->count++;
        }
        else
        {
            printf("    Warning: circular buffer is full. Ignoring.\n");
        }
    }
    else
    {
        printf("Error: invalid cb.\n");
    }
}

int cb_pop(CircularBuffer* cb)
{
    int value = 0;

    if (NULL != cb)
    {
        if (!cb_is_empty(cb))
        {
            value = cb->buffer[cb->tail];
            cb->tail = (cb->tail + 1) % CB_SIZE;
            cb->count--;
        }
        else
        {
            printf("    Warning: circular buffer is empty. Ignoring.\n");
        }
    }
    else
    {
        printf("Error: invalid cb.\n");
    }

    return value;
}

bool cb_is_full(CircularBuffer* cb)
{
    bool is_full = false;

    if (NULL != cb)
    {
        is_full = (CB_SIZE == cb->count);
    }
    else
    {
        printf("Error: invalid cb.\n");
    }

    return is_full;
}

bool cb_is_empty(CircularBuffer* cb)
{
    bool is_empty = true;

    if (NULL != cb)
    {
        is_empty = (0 == cb->count);
    }
    else
    {
        printf("Error: invalid cb.\n");
    }

    return is_empty;
}

void cb_print(CircularBuffer *cb)
{
    if (NULL != cb)
    {
        printf("    Head: %d    Tail: %d    Count: %d    Is full: %d    Is empty: %d\n", cb->head,
                                                                                         cb->tail,
                                                                                         cb->count,
                                                                                         cb_is_full(cb),
                                                                                         cb_is_empty(cb));
    }
    else
    {
        printf("Error: invalid cb.\n");
    }
}