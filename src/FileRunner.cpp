///@file FileRuner.cpp

#include "../inc/FileRunner.h"

char ** FileRunner (int argc, char * argv[])
{
    if (argc > 3);

    else if (argc == 1)
        return (FileOpener ("../Onejka/OnejkaText.txt"));
    else
    {
        switch (GetFlags (argc, argv[1]))
        {
            case PUT:
            {
                return (FileOpener (argv[2]));
            }
            case HELP:
            {
                HelpList ();
                break;
            }
            case ERROR:
            {
                printf ("Please, enter only one flag.\n");
                break;
            }

            default:
            {
                printf ("You entered something wrong. Be careful.");
                break;
            }
        }
    }
    return 0;
}

/**
 * @brief Function, which return flags
 * \param [in]  argc  Quantity of argv
 * \param [in]  str   Second string from argv
 * \param [out] const What flag User entered
 */

int GetFlags (const int argc, const char* str)
{
    my_assert (str != NULL);
    my_assert (argc > 0);

    if (argc > 3)
    {
        return ERROR;
    }

    if (strcmp (str, "--put") == 0)
    {
        return PUT;
    }
    else
    {
        return ERROR;
    }
}

/**
 * @brief Open the file
 * \param [in] file_directory File name
 */

char ** FileOpener (const char * file_directory)
{
    my_assert (file_directory != NULL);
    
    struct stat to_take_file_size = {};

    stat (file_directory, &to_take_file_size);

    int file_size = to_take_file_size.st_size;

    FILE* file_with_onejka = fopen (file_directory, "r");
    my_assert (file_with_onejka != 0);

    char * str_with_text = (char *) calloc (file_size + 1, sizeof (char));
    my_assert (str_with_text != NULL);

    size_t check_size = fread (str_with_text, sizeof (char), file_size, file_with_onejka);
    my_assert ((int) check_size != file_size + 1);

    str_with_text[file_size] = '\0';

    printf ("End of FileOpener\n");

    return MakeAnArray (str_with_text);
}

/**
 * @brief Make a array of pointers to string
 * \param [in] str_with_test String which include text
 */

char ** MakeAnArray (char * str_with_text)
{
    printf ("Start the MakeAnArray\n");

    int str_quantity = StrCounter (str_with_text);

    char ** text = (char **) calloc (str_quantity, sizeof (char *));
    my_assert (text != NULL);

    printf ("Start makeing array\n");

    LineSplitting (str_with_text, text);

    return text;
}

/**
 * @brief Puts \0 insted of \\n and \r
 * \param [in] pointer       Pointer to start
 * \param [in] str_with_test String which include text
 */

char ** LineSplitting (char * str_with_text, char ** text)
{
    int i = 0;
    int text_index = 0;

    while (str_with_text[i] != '\0')
    {
        if (str_with_text[i] != '\n' && str_with_text[i] != '\r');
        else
        {
            str_with_text[i] = '\0';

            printf ("NULL %c", str_with_text[i]);
            
            if (str_with_text[i + 1] == '\n' || str_with_text[i + 1] == '\r')
            {
                str_with_text[i + 1] = '\0';
                
                printf ("NULL 2 %c", str_with_text[i + 1]);

                text[text_index] = (char *) (i + 2);
                printf ("%s\n", text[text_index]);
                text_index++;
            }
            text[text_index] = (char *) (i + 1);
            printf ("%s\n", text[text_index]);
            text_index++;
        }
        i++;
    }
    return '\0';
}

void HelpList ()
{
    printf ("If You need to open Your own file, write like this:\n\n");
    printf ("[Name of .exe file] --put [Your file with text name]\n");
}