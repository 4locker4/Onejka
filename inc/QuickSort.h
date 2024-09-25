#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>

#include "FileRunner.h"

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define STRANGE "\x1b[1;35;7m"

#define my_assert(expr) if (!(expr))\
                        {\
                            printf ("ERROR: \"" #expr "\", file %s, function %s, line %d\n", \
                                        __FILE__, __func__, __LINE__);\
                            exit (1);\
                        }


#define COLOR_PRINT(color, ...)  { printf (color __VA_ARGS__); printf (RESET); }    ///< Colorful print

extern int counter_iterations = 0;

void Swap64 (void * obj_one, void * obj_two, int bias);
void Swap32 (void * obj_one, void * obj_two, int bias);
void Swap16 (void * obj_one, void * obj_two, int bias);
void Swap8  (void * obj_one, void * obj_two, int bias);

void MyQsort (void * data, size_t size, size_t el_size, int (*Compare) (void * first_obj, void * second_obj));
int ForwardComparator  (void * first_str, void * second_str);
int IntComparater      (void * a, void * b);
void Swapper (void * obj_one, void * obj_two, size_t el_size);