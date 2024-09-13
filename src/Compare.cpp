///@file Compare.cpp

#include "../inc/Compare.h"

/**
 * @brief Returns result of compearing of two strings
 * \param [in] str_one First string
 * \param [in] str_two Second string
 */

int MyStrcmp (const char * str_one, const char * str_two)
{
    my_assert (str_one != NULL);
    my_assert (str_two != NULL);

    int char_counter_one = 0;
    int char_counter_two = 0;

    while (str_one[char_counter_one] != '\0' && str_two[char_counter_two] != '\0')
    {
        if (tolower (str_one[char_counter_one]) > AFTER_z || tolower (str_one[char_counter_one] < BEFOR_a))
        {
            char_counter_one++;
            continue;
        }

        if (tolower (str_two[char_counter_two]) > AFTER_z || tolower (str_two[char_counter_two] < BEFOR_a))
        {
            char_counter_two++;
            continue;
        }

        if (tolower (str_one[char_counter_one]) == tolower (str_two[char_counter_two]))
        {
            char_counter_one++;
            char_counter_two++;
        }
        else
            return (tolower (str_one[char_counter_one]) - tolower (str_two[char_counter_two]));
    }

    return (tolower (str_one[char_counter_one]) - tolower (str_two[char_counter_two]));
}

/**
 * @brief Returns result of compearing of two strings from their`s backs
 * \param [in] str_one First string
 * \param [in] str_two Second string
 */

int MyStrcmpFromBack (const char * str_one, const char * str_two)
{
    my_assert (str_one != NULL);
    my_assert (str_two != NULL);

    int len_str_one = strlen (str_one);
    int len_str_two = strlen (str_two);
    
    while (len_str_one >= 0 && len_str_two >= 0)
    {
        if (tolower (str_one[len_str_one]) > AFTER_z || tolower (str_one[len_str_one] < BEFOR_a))
        {
            len_str_one--;
            continue;
        }

        if (tolower (str_two[len_str_two]) > AFTER_z || tolower (str_two[len_str_two] < BEFOR_a))
        {
            len_str_two--;
            continue;
        }

        if (tolower (str_one[len_str_one]) == tolower (str_two[len_str_two]))
        {
            len_str_one--; 
            len_str_two--;
        }
        else
            return (tolower (str_one[len_str_one]) - tolower (str_two[len_str_two]));
    }
    return (tolower (str_one[len_str_one]) - tolower (str_two[len_str_two]));
    
}   

/**
 * @brief Bubble sort func
 * \param [in] text     Array of pointers to string, which need to sort
 * \param [in] quantity How long are strings
 */

void BubbleSort (char ** text, int text_size)
{
    char * buffer = NULL;

    for (int i = 0; i < text_size - 1; i++)                                             ///< -2 Because text[last_element] if \\0 
        for (int j = 0; j < text_size - 1; j++)
        {
            if (MyStrcmpFromBack (text[j], text[j + 1]) > 0)
            {
                buffer = text[j];

                text[j] = text[j + 1];
                text[j + 1] = buffer;  
            }
        }
}
