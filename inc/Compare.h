///@file Compare.h

#ifndef COMPARE_H
#define COMPARE_H

#include <stdio.h>
#include <string.h>

#include "Errors.h"
#include "FileRunner.h"

const int AFTER_z = 122;
const int BEFOR_a = 97;

int  MyStrcmp          (const char * str_one, const char * str_two);        ///< Compare two strings
int  MyStrcmpFromBack  (const char * str_one, const char * str_two);        ///< Compare two stringsfrom behind
void BubbleSort        (char ** text, int text_size);                       ///< Runs bubble sort 

#endif ///COMPARE_H