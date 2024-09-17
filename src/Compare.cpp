///@file Compare.cpp

#include "../inc/Compare.h"

/**
 * @brief Returns result of compearing of two strings
 * \param [in] str_one First string
 * \param [in] str_two Second string
 */

int Comparator (struct Read_Text * data_first_str, struct Read_Text * data_second_str)
{
    my_assert (data_first_str != NULL);
    my_assert (data_second_str != NULL);

    int char_counter_one = 0;
    int char_counter_two = 0;

    while (data_first_str->strings[char_counter_one] != '\0' && data_second_str->strings[char_counter_two] != '\0')
    {
        if (tolower (data_first_str->strings[char_counter_one]) > AFTER_z || tolower (data_second_str->strings[char_counter_one] < BEFOR_a))
        {
            char_counter_one++;
            continue;
        }

        if (tolower (data_first_str->strings[char_counter_two]) > AFTER_z || tolower (data_second_str->strings[char_counter_two] < BEFOR_a))
        {
            char_counter_two++;
            continue;
        }

        if (tolower (data_first_str->strings[char_counter_one]) == tolower (data_second_str->strings[char_counter_two]))
        {
            char_counter_one++;
            char_counter_two++;
        }
        else
            return (tolower (data_first_str->strings[char_counter_one]) - tolower (data_second_str->strings[char_counter_two]));
    }

    return (tolower (data_first_str->strings[char_counter_one]) - tolower (data_second_str->strings[char_counter_two]));
}

/**
 * @brief Returns result of compearing of two strings from their`s backs
 * \param [in] str_one First string
 * \param [in] str_two Second string
 */

int BackComparator (Read_Text * data_str_one, Read_Text * data_str_two)
{
    my_assert (data_str_one != NULL);
    my_assert (data_str_two != NULL);

    int len_str_one = data_str_one->strings_len;
    int len_str_two = data_str_two->strings_len;
    
    while (len_str_one >= 0 && len_str_two >= 0)
    {
        if (tolower (data_str_one->strings[len_str_one]) > AFTER_z || tolower (data_str_two->strings[len_str_one] < BEFOR_a))
        {
            len_str_one--;
            continue;
        }

        if (tolower (data_str_one->strings[len_str_two]) > AFTER_z || tolower (data_str_two->strings[len_str_two] < BEFOR_a))
        {
            len_str_two--;
            continue;
        }

        if (tolower (data_str_one->strings[len_str_one]) == tolower (data_str_two->strings[len_str_two]))
        {
            len_str_one--; 
            len_str_two--;
        }
        else
            return (tolower (data_str_one->strings[len_str_one]) - tolower (data_str_two->strings[len_str_two]));
    }
    return (tolower (data_str_one->strings[len_str_one]) - tolower (data_str_two->strings[len_str_two]));
    
}   

/**
 * @brief Bubble sort func
 * \param [in] text     Array of pointers to string, which need to sort
 * \param [in] quantity How long are strings
 */

void BubbleSort (struct General * data)
{
    Read_Text buffer = {};

    for (int i = 0; i < data->inputed.n_elements - 1; i++)                                             ///< -2 Because text[last_element] if \\0 
        for (int j = 0; j < data->inputed.n_elements - 1; j++)
        {
            if (data->stanzas[j].strings == '\0' || data->stanzas[j + 1].strings == '\0')
                continue;
            if (BackComparator (&data->stanzas[j], &data->stanzas[j + 1]) > 0)
            {
                buffer = data->stanzas[j];

                data->stanzas[j] = data->stanzas[j + 1];
                data->stanzas[j + 1] = buffer;  
            }
        }
}
