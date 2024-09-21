///@file FileRuner.cpp

#include "../inc/FileRunner.h"

const char * INPUT_FILE_NAME  = "./OnejkaText.txt";
const char * OUTPUT_FILE_NAME = "./Onejka/Result.txt";

/**
 * @brief Read and sort file
 * \param [in] data           Struct of all file data
 * \param [in] file_directory File`s directory
 */

void FileReader (General * data)
{
    my_assert (data != NULL);
    COLOR_PRINT (GREEN, "FileReader: open FileToStr\n");
    data->text = FileToStr (INPUT_FILE_NAME);
    COLOR_PRINT (GREEN, "FileReader: Now let`s spliiiiiiiit\n");

    LineSplitting (data);
}

/**
 * @brief Open the file
 * \param [in] file_directory File name
 */

char * FileToStr (const char * file_directory)                          
{
    my_assert (file_directory != NULL);


    size_t file_size = ReadFileSize (INPUT_FILE_NAME);

    COLOR_PRINT (GREEN, "%d\n", file_size);

    FILE* file_with_onejka = fopen (INPUT_FILE_NAME, "rb");
    my_assert (file_with_onejka != 0);

    char * pointer_to_text = NULL;

    pointer_to_text = (char *) calloc (file_size + 1, sizeof (char));
    my_assert (file_size != 0);

    size_t check_size = (int) fread (pointer_to_text, sizeof (char), file_size, file_with_onejka);
    my_assert (check_size == file_size);

    pointer_to_text[file_size] = '\0';

    return pointer_to_text;
}

size_t ReadFileSize (const char * file_directory)
{
    my_assert (file_directory != NULL);

    struct stat to_take_file_size = {};
    stat (file_directory, &to_take_file_size); //Check stat 
    my_assert (to_take_file_size.st_size != NULL);

    return to_take_file_size.st_size;
}


/**
 * @brief Puts \0 insted of \\n and \r
 * \param [in] pointer       Pointer to start
 * \param [in] str_with_test String which include text
 */

void LineSplitting (General * data)
{
    my_assert (data != NULL);
    int stanzas_n = 0;
    int index = 0;

    data->n_elements = StrCounter (data->text);

    COLOR_PRINT (GREEN, "We got n_elements <%d>\n", data->n_elements);

    data->stanzas = (Read_Text *) calloc (data->n_elements, sizeof (Read_Text));
    my_assert (data->stanzas != NULL);

    while (data->text[index] != '\0')
    {
        if (data->text[index] == '\r')
        {
            COLOR_PRINT (RED, "HELPHELPHELP\n");
            data->text[index] = '\0';

            data->stanzas[stanzas_n].strings = &data->text[index];
            stanzas_n++;
            COLOR_PRINT (RED, "%d - n_stanza\n", stanzas_n);
            index++;
            COLOR_PRINT (RED, "%s\n", data->stanzas[stanzas_n - 1]);

        }

        index++;

    }
}

/**
 * @param Write datas in result file
 * \param [in] data Struct with all files data
 */

void FileWithResult (General * data)
{
    FILE * result = fopen (OUTPUT_FILE_NAME, "w");
    my_assert (fopen != NULL);
    COLOR_PRINT (RED, "%s \n%d", data->stanzas[200].strings, data->stanzas[200].strings_len);
    for (size_t i = 0; i < data->file_size; i++)
    {
        fwrite (data->stanzas[i].strings, data->stanzas[i].strings_len, data->stanzas[i].strings_len, result);
        fwrite ("\n", 1, 1, result);
        i++;
    }
    MemCleaner (data);

    my_assert (fclose (result));
}

void MemCleaner (General * data)
{
    free (data->text);
    free (data->stanzas);

    //General data {};
}