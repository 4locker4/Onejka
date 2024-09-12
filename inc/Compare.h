///@file Compare.h

#ifndef COMPARE_H
#define COMPARE_H

#include <stdio.h>
#include <string.h>

#include "Errors.h"
#include "FileRunner.h"

const int REVERS   = -1;                                                    ///< If we need to find not-letter char from behind 
const int STRAIGHT =  1;                                                    ///< If we need to find not-letter char from beginning

int  MyStrcmp          (const char * str_one, const char * str_two);        ///< Compare two strings
int  MyStrcmpFromBack  (const char * str_one, const char * str_two);        ///< Compare two stringsfrom behind
int  HowManyNotLetters (const char * str, int arg);                         ///< Find not-letter symbols
void BubbleSort        (char ** text, int quantity);                        ///< Runs bubble sort 

#endif ///COMPARE_H