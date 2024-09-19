// #include "../inc/QuickSort.h"

// void MyQsort (char ** data, size_t size, size_t el_size, int (*Comparater) (void * a, void * b))
// {

// /*  Pivot is last value of array  */
//     size_t more = 0;
//     char * 

//     for (size_t i = 0; i < size; i += el_size)
//     {
//         while (Comparater (data + i, data + size - el_size) <= 0)                                           ///< While [element] < pivot
            // i += el_size;                                                                                   ///< Going to next element
//         more = i;       /// или инициализировать его до фора?                                                                                    ///< Addres of first string`s element, which > pivot

//         while (Comparater (data + i, data + size - el_size) > 0)                                            ///< While every elements > pivot
//             i += el_size;                                                                                   ///< Going to check next element

//         char * buffer = NULL;

//         buffer = *(data + i);
//         *(data + i) = *(data + more);
//         *(data + more) = *(data + i);

//         while ;

//     }
// }
