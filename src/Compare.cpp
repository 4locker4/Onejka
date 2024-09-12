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

    int char_counter_one = HowManyNotLetters (str_one, STRAIGHT);
    int char_counter_two = HowManyNotLetters (str_two, STRAIGHT);

    while (str_one[char_counter_one] != '\0' && str_two[char_counter_two] != '\0')
    {
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

    int not_letters_in_one = HowManyNotLetters (str_one, REVERS);
    int not_letters_in_two = HowManyNotLetters (str_two, REVERS);

    int len_str_one = strlen (str_one) - not_letters_in_one - 1;
    int len_str_two = strlen (str_two) - not_letters_in_two - 1;
    
    if (len_str_one < len_str_two)
    {
        for (;len_str_one >= 0;)
        {
            if (tolower (str_one[len_str_one]) == tolower (str_two[len_str_two]))
                continue;
            else
                return (tolower (str_one[len_str_one]) - tolower (str_two[len_str_two]));
            len_str_one--; 
            len_str_two--;
        }
    }
    else
    {
        for (;len_str_two >= 0;)
        {
            if (tolower (str_one[len_str_one]) == tolower (str_two[len_str_two]))
            {
                continue;
            }
            else
                return (tolower (str_one[len_str_one]) - tolower (str_two[len_str_two]));
            len_str_two--;
            len_str_one--;
        }
    }
    return (tolower (str_one[len_str_one]) - tolower (str_two[len_str_two]));
    
}   

/**
 * @brief Count how many not-letters chars are in brgginning\end of string
 * \param [in] str String with letters
 * \param [in] arg Argument, which gave instruction to compare strings from beginning or end
 */

int HowManyNotLetters (const char * str, int arg)
{
    int not_letters = 0;
    if (arg == STRAIGHT)
    {
        while (int charc = tolower (str[not_letters]) < 97 || charc > 122)
        {
            not_letters++;
        }
    }
    else
    {   
        int str_len = strlen (str) - 1;

        while (int charc = tolower (str[str_len]) < 97 || charc > 122)
            {
                COLOR_PRINT (RED, "SUKAAAA\n");
                not_letters++;
                str_len--;
            }
    }
    printf ("%d\n", not_letters);
    return not_letters;
}

/**
 * @brief Bubble sort func
 * \param [in] text     Array of pointers to string, which need to sort
 * \param [in] quantity How long are strings
 */

void BubbleSort (char ** text, int text_size)
{
    char * buffer = NULL;

    for (int i = 0; i < text_size - 1; i++)
        for (int j = 0; j < text_size - 2; j++)
        {
            if (text[j] == NULL || text[j + 1] == NULL)
                continue;
            if (MyStrcmpFromBack (text[j], text[j + 1]) > 0)
            {
                buffer = text[j];

                text[j] = text[j + 1];
                text[j + 1] = buffer;  
            }

        }
    
}
