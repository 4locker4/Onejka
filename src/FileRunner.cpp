///@file FileRuner.cpp

#include "../inc/FileRunner.h"

void Menu (int argc, char * argv[], struct General * data)
{
    if (argc > 3)
        printf ("You entered too many flags\n");

    else if (argc == 1)
    {
        FileRunner (data, "./OnejkaText.txt");
    }
    else
    {
        switch (GetFlags (argc, argv[1]))
        {
            case PUT:
            {
                FileRunner (data, argv[2]);
            }
            case HELP:
            {
                HelpList ();
                break;
            }
            case ERROR:
            {
                printf ("Something went wrong.\n");
                break;
            }

            default:
            {
                printf ("You entered something wrong. Be careful.\n");
                break;
            }
        }
    }
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
 * @brief Read and sort file
 * \param [in] data           Struct of all file data
 * \param [in] file_directory File`s directory
 */

void FileRunner (struct General * data, const char * file_directory)
{
    COLOR_PRINT (GREEN, "FileRunner: starting FileOpener...\n");
    FileOpener (file_directory, data);

    COLOR_PRINT (GREEN, "FileRunner: starting MakeAnArray...\n");
    MakeAnArray (data);

    COLOR_PRINT (GREEN, "FileRunner: starting LineSplitting...\n");
    LineSplitting (data);

    COLOR_PRINT (GREEN, "FileRunner: starting BubbleSort...\n");
    BubbleSort (data);

}

/**
 * @brief Open the file
 * \param [in] file_directory File name
 */

void FileOpener (const char * file_directory, struct General * data)
{
    my_assert (file_directory != NULL);

    struct stat to_take_file_size = {};

    stat (file_directory, &to_take_file_size);

    data->inputed.str_len = to_take_file_size.st_size;

    FILE* file_with_onejka = fopen (file_directory, "rb");
    my_assert (file_with_onejka != 0);

    data->inputed.text = (char *) calloc (data->inputed.str_len + 1, sizeof (char));
    my_assert (data->inputed.str_len != 0);

    size_t check_size = (int) fread (data->inputed.text, sizeof (char), data->inputed.str_len, file_with_onejka);
    my_assert (check_size == data->inputed.str_len);

    data->inputed.text[data->inputed.str_len] = '\0';

    data->inputed.n_elements = StrCounter (data->inputed.text);
}

/**
 * @brief Make a array of pointers to string
 * \param [in] str_with_test String which include text
 */

void MakeAnArray (struct General * data)
{
    data->stanzas = (Read_Text *) calloc (data->inputed.n_elements + 1, sizeof (Read_Text));
    my_assert (data->stanzas != NULL);
}

/**
 * @brief Puts \0 insted of \\n and \r
 * \param [in] pointer       Pointer to start
 * \param [in] str_with_test String which include text
 */

void LineSplitting (struct General * data)
{
    int i = 0;
    int text_index = 0;

    if (data->inputed.text[0] != '\n' && data->inputed.text[0] != '\r')
    {
        data->stanzas[text_index].strings = data->inputed.text;

        text_index++;
    }

    while (data->inputed.text != '\0')
    {
        COLOR_PRINT (RED, "FUUUCK <%d>\n", i);
        if (data->inputed.text[i] != '\r' && data->inputed.text[i] != '\n')
            i++;
        else
        {
            data->inputed.text[i] = '\0';
            COLOR_PRINT (GREEN, "Now lets take strlen\n");

            (data->stanzas[text_index]).strings_len = strlen (((data->stanzas[text_index]).strings));
            COLOR_PRINT (GREEN, "We made it\n");

            i++;

            if (data->inputed.text[i] != '\n' && data->inputed.text[i] != '\r')
            {
                data->stanzas[text_index].strings = &data->inputed.text[i];

                text_index++;
                i++;
            }
        }
    }
}

/**
 * @brief Info for User
 */

void HelpList ()
{
    printf ("If You need to open Your own file, write like this:\n\n");
    printf ("[Name of .exe file] --put [Your file with text name]\n");
}

/**
 * @param Write datas in result file
 * \param [in] data Struct with all files data
 */

void FileWithResult (struct General * data)
{
    FILE * result = fopen ("../Onejka/Result.txt", "w");
    my_assert (fopen != NULL);

    char next_str = '\n';

    for (size_t i = 0; i < data->inputed.str_len; i++)
    {
        fwrite (data->stanzas[i].strings, data->stanzas[i].strings_len, data->stanzas[i].strings_len, result);
        fwrite (&next_str, 1, 1, result);
        i++;
    }
    free (data->inputed.text);
    free (data->stanzas);

    int end = fclose (result);
    my_assert (end == 0);
}
