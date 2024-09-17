#ifndef QUICKSORT_H
#define QUICHSORT_H

#include <stdio.h>

void MyQsort (void * data[], size_t size, size_t el_size, int(*compare_func) (void * a, void * b));

#endif