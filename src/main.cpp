#include "../inc/main.h"

int main ()
{
    char text[ARRAY_LEN][STR_LEN] = {"winter! The peasant, celebrating,//\t...",
                                     "ainter! The peasant, celebraping,-=-=-=-``",
                                     "in a flat sledge inaugurates the track;",
                                     "his naggy, having sensed the snow,",
                                     "shambles at something like a trot.",
                                     "Plowing up fluffy furrows,",
                                     "a bold kibitka flies:",
                                     "the driver sits upon his box",
                                     "in sheepskin coat, red-sashed.",
                                     "Here runs about a household lad,",
                                     "upon a hand sled having seated “blackie,”",
                                     "having transformed himself into the steed;",
                                     "the scamp already has frozen a finger.",
                                     "He finds it both painful and funny — while",
                                     "his mother, from the window, threatens him..."};

   printf ("%d\n", MyStrcmp (text[0], text[1]));
   printf ("%d\n", MyStrcmpFromBack (text[0], text[1]));
   return 0;
}