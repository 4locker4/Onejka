///@file main.cpp

#include "../inc/Compare.h"

int main ()
{
    COLOR_PRINT (STRANGE, "OKEEEEY BODYY lets GOOooOOOOoOoOOOOooOooOoOOo\n");
    General data {};                                            ///< Struct with all file datas
    COLOR_PRINT (GREEN, "main: breaking in FileReader\n");
    FileReader (&data);                                         ///< Read from file

    BubbleSort (&data, BackComparator);                         ///< Sort stanzas

    FileWithResult (&data);                                     ///< Write sorted Onejka

    return 0;
}
