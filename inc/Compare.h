///@file Compare.h

#ifndef COMPARE_H
#define COMPARE_H

#include <stdio.h>
#include <string.h>

#include "Errors.h"
#include "FileRunner.h"

int  ForwardComparator   (void * data_first_str, void * data_second);                                               ///< Compare two strings
int  BackComparator      (void * data_str_one,   void * data_str_two);                                              ///< Compare two stringsfrom behind
void BubbleSort          (General * data, int (*Comparator)(void * first_str, void * second_str));                  ///< Runs bubble sort 
                                                     

#endif ///not COMPARE_H
