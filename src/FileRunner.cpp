///@file FileRuner.cpp

#include "../inc/FileRunner.h"

char ** FileRunner (int argc, char * argv[])
{
    if (argc > 3)
        printf ("You entered too many flags\n");

    else if (argc == 1)
    {
        printf ("FileRunner: start opening FileOpener");
        return (FileOpener ("C:/Users/eremc/Desktop/Onegin.txt"));
    }
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
                printf ("Sommething went wrong.\n");
                break;
            }

            default:
            {
                printf ("You entered something wrong. Be careful.\n");
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

    COLOR_PRINT (RED, "FileOpener: struct created\n");

    stat (file_directory, &to_take_file_size);

    int file_size = to_take_file_size.st_size;

    COLOR_PRINT (RED, "FileOpener: fileSize taken\n");

    FILE* file_with_onejka = fopen (file_directory, "r");
    my_assert (file_with_onejka != 0);

    COLOR_PRINT (RED, "FileOpener: Text file opened \n");

    char * str_with_text = (char *) calloc (file_size + 1, sizeof (char));
    my_assert (str_with_text != NULL);

    COLOR_PRINT (RED, "FileOpener: str_with_text created\n");

    size_t check_size = fread (str_with_text, sizeof (char), file_size, file_with_onejka);
    my_assert ((int) check_size != file_size + 1);

    COLOR_PRINT (RED, "FileOpener: str_with_text full\n");

    str_with_text[file_size] = '\0';

    int len = StrCounter (str_with_text);

    COLOR_PRINT (RED, "FileOpener: Start MakeAnArray\n");

    char ** text = MakeAnArray (str_with_text);

    COLOR_PRINT (RED, "FileOpener: Bubble sort starting\n");

    BubbleSort (text, len);

    printf ("<%s>\n<%s >\n", text[0], text[1]);

    COLOR_PRINT (STRANGE, "FileOpener: Bubble ends\n");

    return text;
}

/**
 * @brief Make a array of pointers to string
 * \param [in] str_with_test String which include text
 */

char ** MakeAnArray (char * str_with_text)
{
    int str_quantity = StrCounter (str_with_text);

    COLOR_PRINT (GREEN, "MakeAnArray: str_quantity taken\n");

    char ** text = (char **) calloc (str_quantity + 1, sizeof (char *));
    my_assert (text != NULL);

    COLOR_PRINT (GREEN, "MakeAnArray: we have text!\n");

    text[str_quantity] = '\0';

    COLOR_PRINT (GREEN, "MakeAnArray: Start LineSplitting\n");

    LineSplitting (str_with_text, text);

    COLOR_PRINT (YELLOW, "MakeAnArray: LineSplitting ends\n");

    return text;
}

/**
 * @brief Puts \0 insted of \\n and \r
 * \param [in] pointer       Pointer to start
 * \param [in] str_with_test String which include text
 */

void LineSplitting (char * str_with_text, char ** text)
{
    int i = 0;
    int text_index = 0;

    if (str_with_text[0] != '\n' && str_with_text[0] != '\r')
    {
        text[text_index] = str_with_text;

        //COLOR_PRINT (YELLOW, "LineSplitting:\n%s\n", text[text_index]);

        text_index++;
    }

    while (str_with_text[i] != '\0')
    {
        if (str_with_text[i] != '\n' && str_with_text[i] != '\r')
            i++;
        else
        {
            str_with_text[i] = '\0';
            i++;

            if (str_with_text[i] != '\n' && str_with_text[i] != '\r')
            {
                
                text[text_index] = &str_with_text[i];

                //COLOR_PRINT (YELLOW, "LineSplitting:\n%30s\n", text[text_index]);

                text_index++;
                i++;
            }
        }
    }
}

void HelpList ()
{
    printf ("If You need to open Your own file, write like this:\n\n");
    printf ("[Name of .exe file] --put [Your file with text name]\n");
}

void FileWithResult (char ** text)
{
    int i = 0;

    FILE * result = fopen ("../Onejka/Result.txt", "w");

    my_assert (fopen != NULL);

    char next_str = '\n';

    while (text[i] != '\0')
    {
        fwrite (text[i], strlen (text[i]), 1, result);
        fwrite (&next_str, 1, 1, result);
        i++;
    }
    
    fclose (result);
}
