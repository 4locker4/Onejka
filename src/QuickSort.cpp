#include "../inc/QuickSort.h"

void MyQsort (char ** data, size_t size, size_t el_size, int (*Comparater) (void * a, void * b))
{

/*  Pivot is last value of array  */

    char * less   = *data;
    char * more   = *data;
    char * buffer = NULL;

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
            
            *(more) = data[0] + i;
            *(data + i) = more;
        }
        else
            i += el_size;

    }
}