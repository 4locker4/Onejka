//#include "../inc/main.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

const int STR_LEN = 48;
const int ARRAY_LEN = 15;

int MyStrcmp (const char * str_one, const char * str_two);
int MyStrcmpFromBack (const char * str_one, const char * str_two);

int main ()
{
    char text[ARRAY_LEN][STR_LEN] = {"winter! The peasant, celebrating,",
                                     "zinter! The peasant, celebrating,",
                                     "in a flat sledge inaugurates the track;",
                                     "his naggy, having sensed the snow,",
                                     "shambles at something like a trot.",
                                     "Plowing up fluffy furrows,",
                                     "a bold kibitka flies:",
                                     "the driver sits upon his box",
                                     "in sheepskin coat, red-sashed.",
                                     "Here runs about a household lad,",
                                     "upon a hand sled having seated “blackie,”",
                                     "having transformed himself into the steed;",
                                     "the scamp already has frozen a finger.",
                                     "He finds it both painful and funny — while",
                                     "his mother, from the window, threatens him..."};

    

    double swiper = 0;

    for (int i = 0; i < ARRAY_LEN; i++)
    {
        for (int j = 0; j < ARRAY_LEN - 1; j++)
        {
            if (MyStrcmp (text[j], text[j + 1]) < 0)
            {
                for (int k = 0; k < 6; k++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        char * addres = & (char) swiper;
                    }
                }
            }
        }
    }
    
   printf ("%d\n", MyStrcmp (text[0], text[1]));
   printf ("%d\n", MyStrcmpFromBack (text[0], text[1]));


}

/**
 * @brief Returns result of compearing of two strings ПЕРЕДЕЛАТЬ
 * \param [in] text Array of strings
 */

int MyStrcmp (const char * str_one, const char * str_two)
{
    assert (str_one != NULL);
    assert (str_two != NULL);

    printf ("%s\n%s\n", str_one, str_two);

    int char_counter = 0;

    while (str_one[char_counter] != '\0')
    {
        if (str_one[char_counter] == str_two[char_counter])
        {
            char_counter++;
            continue;
        }
        else
            return (str_one[char_counter] - str_two[char_counter]);
    }

    return (str_one[char_counter] - str_two[char_counter]);
}

int MyStrcmpFromBack (const char * str_one, const char * str_two)
{
    assert (str_one != NULL);
    assert (str_two != NULL);

    int len_str_one = strlen (str_one);
    int len_str_two = strlen (str_two);

    printf ("%s\n%s\n", str_one, str_two);
    int char_counter = 0;
    
    if (len_str_one < len_str_two)
    {
        char_counter = len_str_one - 1;
        for (;char_counter >= 0; char_counter--)
        {
            if (str_one[char_counter] == str_two[char_counter])
            {
                char_counter--;
                continue;
            }
            else
                return (str_one[char_counter] - str_two[char_counter]);
        }
    }
    else
    {
        char_counter = len_str_two - 1;
        for (;char_counter >= 0; char_counter--)
        {
            if (str_one[char_counter] == str_two[char_counter])
            {
                continue;
            }
            else
                return (str_one[char_counter] - str_two[char_counter]);
        }
    }

    return 0;
}

void FileReader ();