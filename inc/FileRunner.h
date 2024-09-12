///@file FileRuner.h

#ifndef FILERUNNER_H
#define FILERUNNER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "Utils.h"
#include "Errors.h"

enum UsersChoise
{
    ERROR = -1,                                                                          ///< If user enter something  wrong
    PUT   = 'p',                                                                         ///< To put Your file                                                                       ///< To start tests
    HELP  = 'h'                                                                          ///< To take help
};
 
char ** FileRunner    (int argc, char * argv[]);                                         ///< Start to work with file
char ** FileOpener    (const char * file_directory);                                     ///< Open file with text
char ** MakeAnArray   (char * str_with_text);                                            ///< Puts ponters to strings in array
char ** LineSplitting (char * str_with_text, char ** text);                             ///< Return pointer to string
int     GetFlags      (const int argc, const char* str);                                 ///< Get flags from argv[] input
void    HelpList      ();                                                                ///< Print instruction for user

#endif ///FILERUNNER_H