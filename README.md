# garbagecollector
Trabalho da disciplina de Linguagens de Programação onde implementaremos um coletor de lixo na linguagem C utilizando a técnica de contagem de referências
- coletor.c :
  Código fonte da biblioteca estática libcoletor.a
  Contém as funções utilizadas no programa:
  - void* malloc2 (int tamanho) -> aloca um endereço de memória e retorna-o.
  - void coleta() -> Exclui os espaços alocados para cada endereço cujo contador de referências chegou a 0.
  - void atrib2 (void **endereco1, void *endereco2) -> faz a referência de um endereço apontar para outro, atualizando seus contadores de referência
  - void dump() -> exibe o heap

- coletor.h : arquivo de cabeçalho da biblioteca estática
  Possui a definição da estrutura do heap (aqui implementado como uma lista encadeada simples) e a declaração de uma variável que simula este heap
  
- main.c : execução do programa (teste das funções que manipulam o heap e do coletor)

- libcoletor.a: arquivo da biblioteca que será linkado ao main.c na compilação
