///@file FileRuner.cpp

#include "../inc/FileRunner.h"

/**
 * @brief Read and sort file
 * \param [in] data           Struct of all file data
 * \param [in] file_directory File`s directory
 */

void ProgrammRunner (General * data)
{
    COLOR_PRINT (GREEN, "FileRunner: starting FileOpener...\n");
    FileToStr (data);
    COLOR_PRINT (GREEN, "FileRunner: starting LineSplitting...\n");
    LineSplitting (data);
    COLOR_PRINT (GREEN, "FileRunner: starting BubbleSort...\n");
    BubbleSort (data, BackComparator);
}

/**
 * @brief Open the file
 * \param [in] file_directory File name
 */

void FileToStr (General * data)
{
    data->file_size = ReadFileSize (INPUT_FILE_NAME);

    FILE* file_with_onejka = fopen (INPUT_FILE_NAME, "rb");
    my_assert (file_with_onejka != 0);

    data->text = (char *) calloc (data->file_size + 1, sizeof (char));
    my_assert (data->file_size != 0);

    size_t check_size = (int) fread (data->text, sizeof (char), data->file_size, file_with_onejka);
    my_assert (check_size == data->file_size);

    data->text[data->file_size] = '\0';
}

size_t ReadFileSize (const char * file_directory)
{
    my_assert (file_directory != NULL);

    struct stat to_take_file_size = {};

    stat (file_directory, &to_take_file_size);

    return to_take_file_size.st_size;
}


/**
 * @brief Puts \0 insted of \\n and \r
 * \param [in] pointer       Pointer to start
 * \param [in] str_with_test String which include text
 */

void LineSplitting (General * data)
{
    int stanzas_n = 0;

    data->n_elements = StrCounter (data->text);

    data->stanzas = (Read_Text *) calloc (data->n_elements, sizeof (Read_Text));
    my_assert (data->stanzas != NULL);

    if (data->text[0] != '\r')
    {
        (data->stanzas[stanzas_n]).strings = data->text;
    }

    while (data->text != '\0')
    {
        COLOR_PRINT (RED, "FUUUCK\n");
        if (*data->text != '\r')
            data->text++;
        else
        {
            *data->text= '\0';
            COLOR_PRINT (GREEN, "Now lets take strlen\n");

            (data->stanzas[stanzas_n]).strings_len = strlen (((data->stanzas[stanzas_n]).strings));
            COLOR_PRINT (GREEN, "We made it\n");

            stanzas_n++;
            data->text++;

            if (*data->text != '\r')
            {
                data->stanzas[stanzas_n].strings = data->text;

                stanzas_n++;
                data->text += 2;
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

void FileWithResult (General * data)
{
    FILE * result = fopen (OUTPUT_FILE_NAME, "w");
    my_assert (fopen != NULL);

    char next_str = '\n';

    for (size_t i = 0; i < data->file_size; i++)
    {
        fwrite (data->stanzas[i].strings, data->stanzas[i].strings_len, data->stanzas[i].strings_len, result);
        fwrite (&next_str, 1, 1, result);
        i++;
    }
    free (data->text);
    free (data->stanzas);

    int end = fclose (result);
    my_assert (end == 0);
}
