#include <stdio.h>
#include <stdlib.h>

#define my_assert(expr) if (expr)\
                        {\
                            printf ("ERROR: \"" #expr "\"File %s, function %s, line %d\n", \
                                      __FILE__, __func__, __LINE__); \ 
                            exit (1); \
                        }