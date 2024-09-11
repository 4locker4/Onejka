#include <stdio.h>
#include <stdlib.h>

#define my_assert(expr) if (expr)\
                        {\
                            COLOR_PRINT(RED, "ERROR: \"" #expr "\", file %s, function %s, line %d\n", \
                                        __FILE__, __func__, __LINE__);\
                            exit (1);\
                        }
