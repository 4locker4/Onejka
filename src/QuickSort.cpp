#include "../inc/QuickSort.h"

void MyQsort (void ** data, size_t size, size_t el_size, int (*Comparater) (void * a, void * b))
{

/*  Pivot is last value of array  */

    void * less   = data;
    void * more   = data;
    void * buffer = NULL;

    int less_ind = 0;
    int more_ind = 0;

    if (Comparater ((char *) data, (char *) data + (size - 1) * el_size) > 0)
        {
            more = (char *) data + (size - 1) * el_size;
        }

    size_t i = 0;

    while (i < size)
    {
        if (Comparater ((char *) data + i, (char *) data + size - el_size) < 0)
        {
            more = (char *) data + i;
            
            while (Comparater ((char *) data + i, (char *) data + size - el_size) < 0)
            {
                i += el_size;
            }
        }
        else
            i += el_size;

    }
}