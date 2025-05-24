#ifndef ALLOCATE_H
#define ALLOCATE_H

int **allocate_2d(const int rows, const int cols);
void free_2d(int ** const array, const int rows);

#endif // ALLOCATE_H