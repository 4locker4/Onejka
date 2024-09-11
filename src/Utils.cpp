#include "../inc/Utils.h"

int StrCounter (char * str_with_text)
{
    int counter = 0;
    int iteration = 0;

    while (str_with_text[iteration] != '\0')
    {
        if (str_with_text[iteration] == '\n')
            counter++;
        iteration++;
    }

    return counter;
}