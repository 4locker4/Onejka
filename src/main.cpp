///@file main.cpp

#include "../inc/FileRunner.h"

int main (int argc, char * argv[])
{
    struct General data = {};

    COLOR_PRINT (GREEN, "main: Opening menu\n");

    Menu (argc, argv, &data);

    FileWithResult (&data);

    return 0;
}