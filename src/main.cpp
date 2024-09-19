///@file main.cpp

#include "../inc/FileRunner.h"

int main ()
{
    General data = {};

    COLOR_PRINT (GREEN, "main: Opening menu\n");
    ProgrammRunner (&data);

    FileWithResult (&data);

    return 0;
}
