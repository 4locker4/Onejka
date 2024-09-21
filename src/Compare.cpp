///@file Compare.cpp

#include "../inc/Compare.h"
#include "../inc/FileRunner.h"

/**
 * @brief Returns result of compearing of two strings
 * \param [in] str_one First string
 * \param [in] str_two Second string
 */

int ForwardComparator (void * first_str, void * second_str)
{
    my_assert (first_str != NULL);
    my_assert (second_str != NULL);

    Read_Text * data_first_str =  (Read_Text *) first_str;
    Read_Text * data_second_str = (Read_Text *) second_str;


    while (!isalpha (*data_first_str->strings))
    {
        data_first_str->strings++;
    }
    
    while (!isalpha (*data_second_str->strings))
    {
        data_second_str->strings++;
    }

    while (data_first_str->strings == data_second_str->strings && data_first_str != '\0')
    {
        data_first_str->strings++;
        data_second_str->strings++;
    }

    return (data_first_str->strings - data_second_str->strings);
}

/**
 * @brief Returns result of compearing of two strings from their`s backs
 * \param [in] first_str  First string
 * \param [in] second_str Second string
 */

int BackComparator (void * first_str, void * second_str)
{
    my_assert (first_str != NULL);
    my_assert (second_str != NULL);

    Read_Text * data_first_str =  (Read_Text *) first_str;
    Read_Text * data_second_str = (Read_Text *) second_str;

    int len_str_one = data_first_str->strings_len;
    while (!isalpha (*data_first_str->strings))
    {
        len_str_one--;
        data_first_str->strings--;
    }

    int len_str_two = data_second_str->strings_len;
    while (!isalpha (*data_second_str->strings))
    {
        len_str_two--;
        data_second_str->strings--;
    }
    
    while (len_str_one >= 0 && len_str_two >= 0)
    {
        if (data_first_str->strings[len_str_one] == data_second_str->strings[len_str_two])
        {
            len_str_one--; 
            len_str_two--;
        }
        else
            break;
    }
    return (data_first_str ->strings[len_str_one] - 
            data_second_str->strings[len_str_two]);
}   

/**
 * @brief Bubble sort func
 * \param [in] text     Array of pointers to string, which need to sort
 * \param [in] quantity How long are strings
 */

void BubbleSort (General * data, int (*Comparator) (void * first_str, void * second_str))
{
    Read_Text buffer = {};

    for (int i = 0; i < data->n_elements - 1; i++)
        for (int j = 0; j < data->n_elements - 1; j++)
        {
            if (data->stanzas[j].strings == '\0' || data->stanzas[j + 1].strings == '\0')
                continue;

            if (Comparator ((void *) &data->stanzas[j], (void *) &data->stanzas[j + 1]) > 0)
            {
                buffer = data->stanzas[j];

                data->stanzas[j]     = data->stanzas[j + 1];
                data->stanzas[j + 1] = buffer;  
            }
        }
}
