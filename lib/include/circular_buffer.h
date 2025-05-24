#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#define CB_SIZE 4

typedef struct CircularBuffer
{
    int buffer[CB_SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer
;

void cb_init(CircularBuffer* cb);
void cb_push(CircularBuffer* cb, const int value);
int cb_pop(CircularBuffer* cb);
bool cb_is_full(CircularBuffer* cb);
bool cb_is_empty(CircularBuffer* cb);
void cb_print(CircularBuffer *cb);

#endif // CIRCULAR_BUFFER_H