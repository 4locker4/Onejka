#include "../inc/QuickSort.h"

int main ()
{
    char * a = "a";
    char * b = "b";
    char * c = "c";
    char * d = "d";
    char * e = "e";
    char * f = "f";
    char * g = "g";
    
    int dota2[7] = 
    {
        -123, 122, 2435, 6, 0, 2, 0
    };

    char * dota2q[7] = 
    {
        e, g, a, c, d, b, f
    };
    
    MyQsort ((void *) dota2, sizeof (dota2), sizeof (*dota2), ForwardComparator);
    for (int i = 0; i < 7; i++)
        printf ("%d ", dota2[i]);
    printf("\n");

    return 0;
}

void MyQsort (void * data, size_t size, size_t el_size, int (*Compare) (void * first_obj, void * second_obj))
{
    int n_elements = size / el_size;                                                                                // n_elements здесь требуется, так как целочисленное деление играет роль
    int more = n_elements * el_size - el_size;
    int less = 0;
    int pivot = (n_elements / 2) * el_size;
    counter_iterations++;
    COLOR_PRINT (STRANGE, "%d\n", counter_iterations);
    COLOR_PRINT (GREEN, "n_elements: %d, more: %d\nless: %d, n_pivot: %d\n", n_elements, more / el_size, less / el_size, pivot / el_size);
    COLOR_PRINT (YELLOW, "pivot: %d\n", *((int *) ((char *) data + pivot)));

    do
    {
        while (Compare ((char *) data + less, (char *) data + pivot) < 0) less += el_size;                     ///< Less than PIVOT
        COLOR_PRINT (GREEN, "n_more: %d\n", less / el_size);

        while (Compare ((char *) data + more, (char *) data + pivot) > 0) more -= el_size;                     ///< More than PIVOT
        COLOR_PRINT (GREEN, "n_less: %d\n", more / el_size);

        for (int i = 0; i < n_elements; i++)
        {
            COLOR_PRINT (RED, "%d ", *((int *) ((char *) data + i * el_size)));
        }
        printf ("\n");

        void * buffer = (char *) data + less;
        printf ("data[more]: %d, data[less]: %d\n", (int *) ((char *) data + less), (int *) ((char *) data + more));

        Swapper ((void *) Read_Text str_one, (void *) Read_text str_two);

        for (int i = 0; i < n_elements; i++)
        {
            COLOR_PRINT (RED, "%d ", *((int *) ((char *) data + i * el_size)));
        }
        printf ("\n");

        less += el_size;
        more -= el_size;
    } while (less < more);
    
    if ((size + el_size - pivot)  / el_size > 2 && (pivot + el_size) / el_size > 2)
    {
        COLOR_PRINT (RED, "pivot: %d, pivot * el_size: %d\nsize - pivot * el_size: %d\nsize: %d\n", pivot, pivot * el_size, size - el_size * pivot, size);
        MyQsort (data, pivot + el_size, el_size, Compare);
        MyQsort ((char *) data + pivot - el_size, size - pivot + el_size, el_size, Compare);
    }
}

void Swapper (void * obj_one, void * obj_two)
{
    
}

void Swap64 (void * obj_one, void * obj_two, int bias)
{
    my_assert (obj_one != NULL);
    my_assert (obj_two != NULL);

    size_t size = sizeof (int64_t);

    int64_t buffer = 0;

    COLOR_PRINT (RED, "<%p> - buffer\n<%p> - obj_one\n<%p> - obj_two\n", &buffer, &obj_one, &obj_two);

    memcpy (&buffer, ((char *) obj_one + bias * size), size);
    memcpy (((char *) obj_one + bias * size), ((char *) obj_two + bias * size), size);
    memcpy (((char *) obj_two + bias * size), &buffer, size);

    COLOR_PRINT (GREEN, "<%p> - buffer\n<%p> - obj_one\n<%p> - obj_two\n\n", &buffer, &obj_one, &obj_two);
}

void Swap32 (void * obj_one, void * obj_two, int bias)
{
    my_assert (obj_one != NULL);
    my_assert (obj_two != NULL);

    size_t size = sizeof (int32_t);

    int32_t buffer = 0;
    
    COLOR_PRINT (RED, "<%p> - buffer\n<%p> - obj_one\n<%p> - obj_two\n", &buffer, &obj_one, &obj_two);

    memcpy (&buffer, ((char *) obj_one + bias * size), size);
    memcpy (((char *) obj_one + bias * size), ((char *) obj_two + bias * size), size);
    memcpy (((char *) obj_two + bias * size), &buffer, size);

    COLOR_PRINT (GREEN, "<%p> - buffer\n<%p> - obj_one\n<%p> - obj_two\n\n", &buffer, &obj_one, &obj_two);
}

void Swap16 (void * obj_one, void * obj_two, int bias)
{
    my_assert (obj_one != NULL);
    my_assert (obj_two != NULL);

    size_t size = sizeof (int16_t) * 8;

    printf ("%d - size\n", size);

    int16_t buffer = 0;

    COLOR_PRINT (RED, "<%p> - buffer\n<%p> - obj_one\n<%p> - obj_two\n", &buffer, &obj_one, &obj_two);
    
    COLOR_PRINT (YELLOW, "\nobj_one - <%d>\nobj_two - <%d>", obj_one, obj_two);
    COLOR_PRINT (YELLOW, "\nbeffer - <%d>\n", buffer);

    memcpy (&buffer, ((char *) obj_one + bias * size), size);
    memcpy (((char *) obj_one + bias * size), ((char *) obj_two + bias * size), size);
    memcpy (((char *) obj_two + bias * size), &buffer, size);

    COLOR_PRINT (YELLOW, "\nobj_one - <%d>\nobj_two - <%d>", obj_one, obj_two);
    COLOR_PRINT (YELLOW, "\nbeffer - <%d>\n", buffer);
    
    COLOR_PRINT (GREEN, "<%p> - buffer\n<%p> - obj_one\n<%p> - obj_two\n\n", &buffer, &obj_one, &obj_two);
}

void Swap8 (void * obj_one, void * obj_two, int bias)
{
    my_assert (obj_one != NULL);
    my_assert (obj_two != NULL);

    size_t size = sizeof (int8_t);

    int8_t buffer = 0;

    COLOR_PRINT (RED, "<%p> - buffer\n<%p> - obj_one\n<%p> - obj_two\n", &buffer, &obj_one, &obj_two);
    
    memcpy (&buffer, ((char *) obj_one + bias * size), size);
    memcpy (((char *) obj_one + bias * size), ((char *) obj_two + bias * size), size);
    memcpy (((char *) obj_two + bias * size), &buffer, size);
    
    COLOR_PRINT (GREEN, "<%p> - buffer\n<%p> - obj_one\n<%p> - obj_two\n\n", &buffer, &obj_one, &obj_two);
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