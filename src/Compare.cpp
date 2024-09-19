///@file Compare.cpp

#include "../inc/Compare.h"

/**
 * @brief Returns result of compearing of two strings
 * \param [in] str_one First string
 * \param [in] str_two Second string
 */

int ForwardComparator (Read_Text * data_first_str, Read_Text * data_second_str)
{
    my_assert (data_first_str != NULL);
    my_assert (data_second_str != NULL);

    int char_counter_one = 0;
    while (isalpha (*data_first_str->strings))
    {
        char_counter_one++;
        data_first_str->strings++;
    }
    
    int char_counter_two = 0;
    while (isalpha (*data_second_str->strings))
    {
        char_counter_two++;
        data_second_str->strings++;
    }

    while (data_first_str->strings[char_counter_one] == data_second_str->strings[char_counter_two])
    {
        if (tolower (data_first_str->strings[char_counter_one]) == tolower (data_second_str->strings[char_counter_two]))
        {
            char_counter_one++;
            char_counter_two++;
        }
    }

    return (tolower (data_first_str->strings[char_counter_one]) - tolower (data_second_str->strings[char_counter_two]));
}

/**
 * @brief Returns result of compearing of two strings from their`s backs
 * \param [in] str_one First string
 * \param [in] str_two Second string
 */

int BackComparator (void * void_str_one, void * void_str_two)
{
    my_assert (void_str_one != NULL);
    my_assert (void_str_two != NULL);

    Read_Text * data_str_one = (Read_Text *) void_str_one;
    Read_Text * data_str_two = (Read_Text *) void_str_two;

    int len_str_one = data_str_one->strings_len;
    while (isalpha (*data_str_one->strings))
    {
        len_str_one--;
        data_str_one->strings++;
    }

    int len_str_two = data_str_two->strings_len;
    while (isalpha (*data_str_two->strings))
    {
        len_str_two--;
        data_str_two->strings++;
    }
    
    while (len_str_one >= 0 && len_str_two >= 0)
    {
        if (tolower (data_str_one->strings[len_str_one]) == tolower (data_str_two->strings[len_str_two]))
        {
            len_str_one--; 
            len_str_two--;
        }
        else
            break;
    }
    return (tolower (data_str_one->strings[len_str_one]) - tolower (data_str_two->strings[len_str_two]));
    
}   

/**
 * @brief Bubble sort func
 * \param [in] text     Array of pointers to string, which need to sort
 * \param [in] quantity How long are strings
 */

void BubbleSort (General * data, int (*Comparator) (void *, void *))
{
    Read_Text buffer = {};

    for (int i = 0; i < data->n_elements - 1; i++)                                             ///< -2 Because text[last_element] if \\0 
        for (int j = 0; j < data->n_elements - 1; j++)
        {
            if (data->stanzas[j].strings == '\0' || data->stanzas[j + 1].strings == '\0')
                continue;
            if (BackComparator ((void *) &(data->stanzas[j]), (void *) &data->stanzas[j + 1]) > 0)
            {
                buffer = data->stanzas[j];

                data->stanzas[j] = data->stanzas[j + 1];
                data->stanzas[j + 1] = buffer;  
            }
        }
}
