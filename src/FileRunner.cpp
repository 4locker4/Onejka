///@file FileRuner.cpp

#include "../inc/FileRunner.h"

const char * INPUT_FILE_NAME  = "./OnejkaText.txt";
const char * OUTPUT_FILE_NAME = "./Onejka/Result.txt";

/**
 * @brief Read and sort file
 * \param [in] data           Struct of all file data
 * \param [in] file_directory File`s directory
 */

void ProgrammRunner (General * data)
{
    my_assert (data != NULL);

    data->text = FileToStr (data);

    LineSplitting (data);
}

/**
 * @brief Open the file
 * \param [in] file_directory File name
 */

char * FileToStr (General * data)
{
    my_assert (data != NULL);

    size_t file_size = ReadFileSize (INPUT_FILE_NAME);

    FILE* file_with_onejka = fopen (INPUT_FILE_NAME, "rb");
    my_assert (file_with_onejka != 0);

    data->text = (char *) calloc (file_size + 1, sizeof (char));
    my_assert (file_size != 0);

    char * pointer_to_text = NULL;

    size_t check_size = (int) fread (pointer_to_text, sizeof (char), file_size, file_with_onejka);
    my_assert (check_size == file_size);

    pointer_to_text[file_size] = '\0';

    return pointer_to_text;
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
    my_assert (data != NULL);
    int stanzas_n = 0;
    int index = 0;

    data->n_elements = StrCounter (data->text);

    data->stanzas = (Read_Text *) calloc (data->n_elements, sizeof (Read_Text));
    my_assert (data->stanzas != NULL);

    while (data->text[index] != '\0')
    {
        if (data->text[index] == '\r')
        {
            data->text[index] = '\0';

            data->stanzas[stanzas_n].strings = data->text + index;
            stanzas_n++;

            index++;
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

    for (size_t i = 0; i < data->file_size; i++)
    {
        fwrite (data->stanzas[i].strings, data->stanzas[i].strings_len, data->stanzas[i].strings_len, result);
        fwrite ("\n", 1, 1, result);
        i++;
    }
    MemCleaner (data);

    my_assert (!fclose (result));
}

void MemCleaner (General * data)
{
    free (data->text);
    free (data->stanzas);

    General data {};
}