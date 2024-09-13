///@file main.cpp

#include "../inc/main.h"

int main (int argc, char * argv[])
{
    printf ("main: Start Working\n");

    char ** text = FileRunner (argc, argv);                        ///< Return text

    printf ("main: FileRunner ends succses\n");

    FileWithResult (text);

    printf ("main: Thats all\n");
    return 0;
}