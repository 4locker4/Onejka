#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

const int STR_LEN = 48;
const int ARRAY_LEN = 15;

const int REVERS = -1;
const int STRAIGHT = 1;

int MyStrcmp (const char * str_one, const char * str_two);
int MyStrcmpFromBack (const char * str_one, const char * str_two);
int HowManyNotLetters (const char * str, int arg);