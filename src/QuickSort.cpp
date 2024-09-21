#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define STRANGE "\x1b[1;35;7m"

#define COLOR_PRINT(color, ...)  { printf (color __VA_ARGS__); printf (RESET); }    ///< Colorful print

extern int counter_iterations = 0;

void MyQsort           (int data[], size_t size, size_t el_size, int (*Comparater) (void * a, void * b));
int ForwardComparator  (void * first_str, void * second_str);
int IntComparater (void * a, void * b);



int main ()
{
    // char * a = "a";
    // char * b = "b";
    // char * c = "c";
    // char * d = "d";
    // char * e = "e";
    // char * f = "f";
    
    int dotpa2[7] = 
    {
        1, -1, 1, -1, 1, -1, 1
    };

    int dota2[7] = 
    {
        123, 122, 2435, 6, 0, 2, 0
    };
    
    MyQsort (dota2, sizeof (dota2), sizeof (*dota2), IntComparater);
    for (int i = 0; i < 7; i++)
        printf ("%d ", dota2[i]);
    printf("\n");
    return 0;
}

void MyQsort (void ** data, size_t size, size_t el_size, int (*Compare) (void * first_obj, void * second_obj))
{
    int n_elements = size / el_size;
    int more = n_elements * el_size - el_size;
    int less = 0;
    int pivot = (n_elements / 2) * el_size;
    counter_iterations++;
    COLOR_PRINT (STRANGE, "%d\n", counter_iterations);
    COLOR_PRINT (GREEN, "n_elements: %d, more: %d\nless: %d, n_pivot: %d\n", n_elements, more, less, pivot);
    COLOR_PRINT (YELLOW, "pivot: %d\n", data[pivot]);

    do
    {
        while (Compare (*data + less, *data + pivot) < 0) less += el_size;                     ///< Less than PIVOT
        COLOR_PRINT (GREEN, "n_more: %d\n", less);

        while (Compare (*data + more, *data + pivot) > 0) more -= el_size;                     ///< More than PIVOT
        COLOR_PRINT (GREEN, "n_less: %d\n", more);

        for (int i = 0; i < n_elements; i++)
        {
            COLOR_PRINT (RED, "%d ", data[i]);
        }
        printf ("\n");

        void * buffer = *data + less;
        printf ("data[more]: %d, data[less]: %d\n", data[less], data[more]);

        data[less] = data[more];
        data[more] = buffer;

        for (int i = 0; i < n_elements; i++)
        {
            COLOR_PRINT (RED, "%d ", data[i]);
        }
        printf ("\n\n");

        less++;
        more--;
    } while (less < more);
    
    if (size / el_size - (pivot - 1) > 2 && (pivot + 1) > 2)
    {
        COLOR_PRINT (RED, "pivot: %d, pivot * el_size: %d\nsize - pivot * el_size: %d\nsize: %d\n", pivot, pivot * el_size, size - el_size * pivot, size);
        MyQsort (data, (pivot + 1) * el_size, el_size, Compare);
        MyQsort (&data[pivot - 1], size - (pivot - 1) * el_size, el_size, Compare);
    }
}

void Swapper (void * obj_one, void * obj_two, size_t el_size)
{

}


int IntComparater (void * a, void * b)
{
    int * a1 = (int *) a;
    int * b1 = (int *) b;

    return (*a1 - *b1);
}

int ForwardComparator (void * first_str, void * second_str)
{
    char * data_first_str  = (char *) first_str;
    char * data_second_str = (char *) second_str;

    while (!isalpha (*data_first_str))
    {
        data_first_str++;
    }
    
    while (!isalpha (*data_second_str))
    {
        data_second_str++;
    }

    while (*data_first_str == *data_second_str && *data_first_str != '\0')
    {
        data_first_str++;
        data_second_str++;
    }

    return (data_first_str - data_second_str);
}

//void MyQsort(int data[], size_t size, size_t el_size, int (*Comparater)(void *a, void *b))
// {
// /*  Pivot is last value of array  */
//     int n_elements = size / el_size;
//     int less  = 0;
//     int more  = n_elements - 1;
//     int pivot = n_elements / 2;

//     COLOR_PRINT (GREEN,"pivot --- %d --- pivot\n", data[pivot]);


//     do {
//         while (IntComparater (&data[less], &data[pivot]) < 0) less++;                                                            ///< Going to next element

//         while (IntComparater (&data[more], &data[pivot]) > 0) more--;                                                             ///< Going to check next element

//         int buffer = NULL;

//         int i = less;
//         while (i <= more)
//         {
//             COLOR_PRINT (RED, "%d ", data[i]);
//             i++;
//         }
//         printf ("\n");
//         buffer     = data[less];
//         data[less] = data[more];
//         data[more] = buffer;

//         i = less;
//         while (i <= more)
//         {
//             COLOR_PRINT (YELLOW, "%d ", data[i]);
//             i++;
//         }
//         printf ("\n");

//         less++;
//         more--;

//         COLOR_PRINT (GREEN, "less = <%d>, more = <%d>\n", less, more);

//     } while (less < more); 

//     if (size / el_size - (pivot - 1) > 2 && (pivot + 1) > 2)
    // {
    //     COLOR_PRINT (RED, "pivot: %d, pivot * el_size: %d\nsize - pivot * el_size: %d\nsize: %d\n", pivot, pivot * el_size, size - el_size * pivot, size);
    //     MyQsort (data, (pivot + 1) * el_size, el_size, Compare);
    //     MyQsort (&data[pivot - 1], size - (pivot - 1) * el_size, el_size, Compare);
    // }
// }