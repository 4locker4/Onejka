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
#include "Compare.h"


struct Text
{
    char *  text;                                                                        ///< String with file`s text
    size_t  str_len;                                                                     ///< String`s lenght
    int     n_elements;                                                                  ///< Quantity of elements
};

struct Read_Text
{
    char * strings;                                                                     ///< Array with pointers to strings
    int    strings_len;                                                                 ///< Array with lenght of every string
};

struct General
{
    struct Text inputed;
    Read_Text * stanzas;
};

enum UsersChoise
{
    ERROR = -1,                                                                             ///< If user enter something  wrong
    PUT   = 'p',                                                                            ///< To put Your file                                                                       ///< To start tests
    HELP  = 'h'                                                                             ///< To take help
};

const char * FILE_NAME = "./OnejkaText.txt";
 
void Menu           (int argc, char * argv[], struct General * data);                       ///< Start to work with file
void FileRunner     (struct General * data, const char * file_directory);                   ///< Read and sort file
void FileOpener     (const char * file_directory, struct General * data);                   ///< Open file with text
void MakeAnArray    (struct General * data);                                                ///< Puts ponters to strings in array
void LineSplitting  (struct General * data);                                                ///< Return pointer to string
int  GetFlags       (const int argc, const char* str);                                      ///< Get flags from argv[] input
void HelpList       ();                                                                     ///< Print instruction for user
void FileWithResult (struct General * data);                                                ///< Write the result in file

#endif ///FILERUNNER_H