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
 
typedef struct 
{ 
    char * strings     = NULL;                                                              ///< Array with pointers to strings
    int    strings_len = 0;                                                                 ///< Array with lenght of every string
} Read_Text;

typedef struct
{ 
    char *      text        = NULL;                                                         ///< String with file`s text
    size_t      file_size   = 0;                                                            ///< String`s lenght
    int         n_elements  = 0;                                                            ///< Quantity of elements                                                                   
    Read_Text * stanzas     = NULL;
} General;
 
void   FileReader     (General * data);                                                     ///< Read and sort file
char * FileToStr      (const char * file_directory);                                        ///< Open file with text
size_t ReadFileSize   (const char * file_directory);                                        ///< Read size of file
void   LineSplitting  (General * data);                                                     ///< Return pointer to string
void   FileWithResult (General * data);                                                     ///< Write the result in file
void   MemCleaner     (General * data);                                                     ///< Clean all dynamic memory

#endif ///FILERUNNER_H
