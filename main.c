#include <stdio.h>
#include <stdlib.h>
#include "coletor.h"

int main(int argc, char const **argv)
{
    int *v = malloc2(sizeof(int));
    *v = 10;
    int *w = malloc2(sizeof(int));
    dump();
    *w = 20;
    system("pause");
    return 0;
}