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
    if (simulaMemoria)
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
    // se a heap estiver vazia não faz nada
    if (!simulaMemoria)
        return;

    Heap *ant, *aux = simulaMemoria;
    // enquanto os elementos na cabeça da lista possuirem contador = 0 serão removidos
    while (aux && aux->contador == 0)
    {
        simulaMemoria = aux->prox;
        printf("Endereco %p removido\n", aux->endereco);
        free(aux);
        aux = simulaMemoria;
    }

    // Remoção de endereços com contador = 0 para o restante da heap
    while (aux)
    {
        if (aux->contador != 0)
        {
            ant = aux;
            aux = aux->prox;
        }
        else
        {
            ant->prox = aux->prox;
            printf("Endereco %p removido\n", aux->endereco);
            free(aux);
            aux = ant->prox;
        }
    }
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
        printf("A heap esta vazia!!!\n\n");
        return;
    }

    Heap *aux = simulaMemoria;
    while (aux)
    {
        if (aux->contador == 0)
        { // remove o endereço da heap se seu contador = 0
            printf("Endereco: %p, Contador = %d\n", aux->endereco, aux->contador);
            aux = aux->prox;
            coleta();
        }
        else
        {
            printf("Endereco: %p, Contador = %d\n", aux->endereco, aux->contador);
            aux = aux->prox;
        }
    }
    printf("\n");
}