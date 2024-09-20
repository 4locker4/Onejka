#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void MyQsort           (char * data[], size_t size, size_t el_size, int (*Comparater) (char * a, char * b));
int  ForwardComparator (char * data_first_str, char * data_second_str);

int main ()
{
    char * a = "a";
    char * b = "b";
    char * c = "c";
    
    char * data[3] = 
    {
        c, a, b
    };
    
    MyQsort (data, (size_t) 24, sizeof (char *), ForwardComparator);
    printf ("%s %s %s \n", data[0], data[1], data[2]);
    return 0;
}

void MyQsort(char * data[], size_t size, size_t el_size, int (*Comparater)(char *a, char *b))
{
/*  Pivot is last value of array  */
    int n_elements = size / el_size;
    printf ("%d\n", n_elements);

    int less  = 0;
    int more  = n_elements - 1;
    int pivot = n_elements / 2;

    printf ("ok\n");

    while (less < more)
    {
        while (Comparater (data[less], data[pivot]) < 0) less++;                                                            ///< Going to next element
        printf ("mamama\n", data[less], data[more]);

        while (Comparater (data[more], data[pivot]) > 0) more--;                                                             ///< Going to check next element

        char * buffer = NULL;

        buffer     = data[less];
        data[less] = data[more];
        data[more] = buffer;

        printf ("%s %s %s \n", data[less], data[more], buffer);
        printf ("%s %s %s -- res\n", data[0], data[1], data[2]);
    }
    less++;

    while (less <= more)
    {
        printf ("enter while\n");
        MyQsort (data, size - (pivot - 1) * el_size, el_size, Comparater);
        MyQsort (data, pivot * (el_size), el_size, Comparater);        
    }
}

int ForwardComparator (void * first_str, void * second_str)
{
    char * data_first_str = (char *) first_str;
    char * data_second_str = (char *) second_str;
    while (!isalpha (*data_first_str))
    {
        data_first_str++;
    }
    
    while (!isalpha (*data_second_str))
    {
        data_second_str++;
    }

    while (data_first_str == data_second_str)
    {
        data_first_str++;
        data_second_str++;
    }

    return (data_first_str - data_second_str);
}