///@file Compare.h

#ifndef COMPARE_H
#define COMPARE_H

#include <stdio.h>
#include <string.h>

#include "Errors.h"
#include "FileRunner.h"

const int AFTER_z = 'z';
const int BEFOR_a = 'a';

int  Comparator          (struct Read_Text * data_first_str, struct Read_Text * data_second);                ///< Compare two strings
int  BackComparator      (struct Read_Text * data_str_one,   struct Read_Text * data_str_two);               ///< Compare two stringsfrom behind
void BubbleSort          (struct General * data);                                                            ///< Runs bubble sort 

#endif ///COMPARE_H