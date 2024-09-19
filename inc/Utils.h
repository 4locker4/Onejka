/// @file Utils.h

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Errors.h"

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define STRANGE "\x1b[1;35;7m"

#define COLOR_PRINT(color, ...)  { printf (color __VA_ARGS__); printf (RESET); }    ///< Colorful print

const double EPSILON = 1e-10;                                                       ///< Error constant double

bool IsZero             (const double val);                                         ///< Double error check
bool DoubleComparison   (const double firstNum, const double secondNum);            ///< Checking equality double
void BufferCleaner      ();                                                         ///< Buffer cleaner
bool SkipSpaces         ();                                                         ///< Skip spaces and tabs after User`s text, returns first char
void FileOpener         (int argc, char * argv[]);                                  ///< Open User`s file
int  StrCounter         (char * fileFirstElement);                                  ///< Count quantity of tests
void TestArrayReturner  (int fileSize, char * fileFirstElement);                    ///< Put values into array of struct (test data array)

#endif ///UTILS_H
