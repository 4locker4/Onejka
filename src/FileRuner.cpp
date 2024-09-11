#include "../inc/FileRuner.h"

char * FileReader (char * file_directory)
{
    assert (file_directory != NULL);

    FILE* file_with_onejka = fopen (file_directory, "r");
    assert (file_with_onejka != 0);

    int file_offset = fseek (file_with_onejka, 0, SEEK_END);
    assert (file_offset != 0);

    rewind (file_with_onejka);

    int file_size = ftell (file_with_onejka);

    char * str_with_text = (char *) calloc (file_size + 1, sizeof (char));
    assert (str_with_text != NULL);

    int check_size = fread (str_with_text, sizeof (char), file_size, file_with_onejka);
    assert (check_size != file_size + 1);

    str_with_text[file_size] = '\0';

    return str_with_text;
}

int MakeAnArray (char * str_with_text)
{
    int str_quantity = StrCounter (str_with_text);

    char ** text = (char **) calloc (str_quantity, sizeof (char*));
    assert (text != NULL);

    const char separators[] = "\n\0";

    int index = 0;

    text[index] = strtok (str_with_text, separators);

    while (text[index])
    {

    }

}

char * PoemMaker (char * str_with_text)
{
    for (int index = 0; index < strlen (str_with_text); index++)
    {
        int counter = 0;
        while (str_with_text[counter] != '\n')

    }
}