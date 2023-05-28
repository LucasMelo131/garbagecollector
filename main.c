#include <stdio.h>
#include <stdlib.h>
#include "coletor.h"

int main(int argc, char const **argv)
{
    dump();
    int *v = malloc2(sizeof(int));
    *v = 10;
    int *w = malloc2(sizeof(int));
    dump();
    *w = 20;
    atrib2(&v, w);
    dump();
    printf("Valor armazenado em v = %d\n\n", *v);
    char *c = malloc2(sizeof(char));
    *c = 'Z';
    dump();
    atrib2(&w, NULL);
    dump();
    atrib2(&v, NULL);
    dump();
    dump();
    return 0;
}