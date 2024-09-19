///@file Compare.h

#ifndef COMPARE_H
#define COMPARE_H

#include <stdio.h>
#include <string.h>

#include "Errors.h"
#include "FileRunner.h"

int  ForwardComparator   (Read_Text * data_first_str, Read_Text * data_second);                           ///< Compare two strings
int  BackComparator      (void * data_str_one,   void * data_str_two);                                    ///< Compare two stringsfrom behind
void BubbleSort          (General * data, int (*Comparator)(void *, void *));                             ///< Runs bubble sort 
                                                     

#endif ///COMPARE_H
