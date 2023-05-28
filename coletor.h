#ifndef _GARBAGE_COLLECTOR_H_
#define _GARBAGE_COLLECTOR_H_

//estrutura que simula a heap
typedef struct mem
{
    int contador; //contador de referencias para o "objeto"
    void *endereco; //endereço do objeto
    struct mem *prox; //endereço do nó adjacente
} Heap;

//declara uma variavel para estrutura usada sem alocar memória para ela
extern Heap *simulaMemoria;

//funções da biblioteca estática
void *malloc2 (int tamanho);
void atrib2(void **endereco1, void *endereco2);
void coleta();
void dump();

#endif //_GARBAGE_COLLECTOR_H_