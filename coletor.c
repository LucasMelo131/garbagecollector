#include <stdio.h>
#include <stdlib.h>
#include "coletor.h"

Heap *simulaMemoria = NULL;

// realiza a alocação dinâmica e retorna o endereço da área criada
void *malloc2(int tamanho)
{
    Heap *end = (Heap *)malloc(sizeof(Heap));

    // insere o endereço de memória na lista(heap)
    end->contador = 1;
    end->endereco = malloc(tamanho);
    end->prox = NULL;

    // se a heap tem elementos, inserimos a nova area alocada no início
    if (simulaMemoria != NULL)
    {
        end->prox = simulaMemoria;
    }

    // se a heap é vazia ela recebe o nó que contém o novo endereço alocado
    simulaMemoria = end;

    // retorna o endereço da nova área alocada
    return simulaMemoria->endereco;
}

// limpa a memória das áreas alocadas com 0 no contador de referencia
void coleta()
{
    Heap *aux = simulaMemoria;
    Heap *next = aux->prox; // recebe a posição posterior da heap

    // se a heap estiver vazia não faz nada
    if (!aux)
        return;

    // se o primeiro elemento tiver contador = 0, removê-lo
    if (aux->contador == 0)
    {
        simulaMemoria = next;
        free(aux->endereco);
        free(aux);
        aux = simulaMemoria;
        next = aux->prox;
    }
    // remove o restante das areas com contador = 0 recursivamente
    coleta();
}

// esta função realiza a atribuição de ponteiros em C
// faz uma referencia a um endereço apontar para outro endereço, assim o primeiro endereço perde
// uma refêrencia(diminui o contador) enquanto o segundo ganha uma mais (aumenta o contador)
void atrib2(void **endereco1, void *endereco2)
{
    // estrutura auxiliar para iterar na lista
    Heap *aux = simulaMemoria;
    // percorre a lista encontrando os enderecos referenciados e atualizando os contadores de referencia de cada um
    while (aux)
    {
        if (aux->endereco == *endereco1)
        {
            aux->contador -= 1;
        }
        if (aux->endereco == endereco2)
        {
            aux->contador += 1;
        }
        aux = aux->prox;
    }

    // faz o ponteiro de endereco 1 apontar para endereco2
    *endereco1 = endereco2;
}

//mostra como está o heap para o usuário
void dump()
{
    if (!simulaMemoria)
    {
        printf("A heap esta vazia!!!");
        return;
    }

    Heap *aux = simulaMemoria;
    while (aux)
    {
        if (aux->contador == 0) // remove o endereço da heap se seu contador = 0
            coleta();
        printf("Endereco: %p, Contador = %d", aux->endereco, aux->contador);
        aux = aux->prox;
    }
}