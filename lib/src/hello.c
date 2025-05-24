#include <stdio.h>

#include "hello.h"

bool say_hello(const char * name, size_t size)
{
    bool success = false;

    const int outputMaxSize = 64;

    char hello[] = "Hello %s, how is it running?\n";
    char output[outputMaxSize];

    if (NULL == name)
    {
        printf("Error: invalid message");
    }
    else if(0 == size)
    {
        printf("Error: size is 0");
    }
    else if((size + sizeof(hello)) > outputMaxSize)
    {
        printf("Error: total size %d is over limit %d", size + sizeof(hello), outputMaxSize);
    }
    else
    {
        snprintf(output, sizeof(output), hello, name);

        printf(output);
        success = true;
    }

    return success;
}