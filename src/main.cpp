///@file main.cpp

#include "../inc/main.h"

int main (int argc, char * argv[])
{
    char ** text = FileRunner (argc, argv);                        ///< Return text
    FileWithResult (text);
    
    return 0;
}