/// @file Utils.cpp

#include "..\inc\Utils.h"

/**
 * @brief Checks double error.
 * \param [in]  val    Value of the input double variable
 * \param [out] return Return is this doouble == 0
 */

bool IsZero (const double val)                                                            // Checking double for errors
{
    my_assert (isfinite (val));

    if (EPSILON >= fabs (val))
    {
        return true;
    }
    return false;
}

/**
 * @brief Compearing two double nums
 * \param [in]  firstNum   First double num
 * \param [in]  secondNum  Second double num
 * \param [out] true/false Is this true or false
 */

bool DoubleComparison (const double firstNum, const double secondNum)               // Compare two double
{
    my_assert (isfinite (firstNum));
    my_assert (isfinite (secondNum));

    return IsZero (firstNum - secondNum);
}

/**
 * @brief Clean buffer
 */

void BufferCleaner ()                                                               // Clean Buffer
{   
    int ch = 0;

    while ((ch = getchar ()) != '\n' && ch != EOF) {}
}

/**
 * @brief Function, which skips spaces after User`s text and returns first not-space char
 * \param [out] lastChar Returns false (not \\n or EOF) or True (if \\n or EOF)
 */

bool SkipSpaces ()
{
    int isSpace = 0;

    while ((isSpace = getchar ()) == ' ' || isSpace == '\t') {}
    
    if (isSpace == '\n' || isSpace == EOF)
    {
        return true;
    }
    return false;
}

/**
 * @brief Counts the number of tests in the file
 * \param [in] fileFirstElement Addres of file first element
 */

int StrCounter (char * fileFirstElement)                                             // Count quantity of tests
{
    printf ("Start StrCounter\n");

    int counterNextStr = 0;
    int i = 0;

    while (fileFirstElement[i] != '\0')
    {
        COLOR_PRINT (RED, "BLYA\n");

        if (fileFirstElement[i] == '\n')
        {
            ++counterNextStr;
        }
        i++;
    }

    return counterNextStr + 1;
}
