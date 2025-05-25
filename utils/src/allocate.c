#include <stdlib.h>
#include <stdio.h>

#include "allocate.h"

int **allocate_2d(const int rows, const int cols)
{
    int **arr = (int **)calloc(rows, sizeof(int *));

    if (NULL != arr)
    {
        for (int i = 0; i < rows; i++)
        {
            arr[i] = (int *)calloc(cols, sizeof(int));
            if (NULL == arr[i])
            {
                printf("Error: invalid arr[%d]", i);
                for (int j = 0; j < i; j++)
                {
                    free(arr[j]);
                }
                free(arr);
                return NULL;
            }
        }
    }
    else
    {
        printf("Error: invalid arr");
    }

    return arr;
}

void free_2d(int ** const array, const int rows)
{
    if (NULL == array) return;

    for (int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);
}