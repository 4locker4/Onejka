///@file main.cpp

#include "../inc/Compare.h"

int main ()
{
    General data {};                                            ///< Struct with all file datas

    ProgrammRunner (&data);                                     ///< Read from file

    BubbleSort (&data, BackComparator);                         ///< Sort stanzas

    FileWithResult (&data);                                     ///< Write sorted Onejka

    return 0;
}
