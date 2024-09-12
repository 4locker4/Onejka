///@file Errors.h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define my_assert(expr) if (!(expr))\
                        {\
                            printf ("ERROR: \"" #expr "\", file %s, function %s, line %d\n", \
                                        __FILE__, __func__, __LINE__);\
                            exit (1);\
                        }
