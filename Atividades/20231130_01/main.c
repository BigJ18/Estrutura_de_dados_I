// main.c
#include <stdio.h>
#include "aluno.h"

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    inserirElementoOrdenado(&lista, 20);
    inserirElementoOrdenado(&lista, 10);
    inserirElementoOrdenado(&lista, 30);

    printf("Quantidade de elementos na lista: %d\n", quantidadeElementos(lista));
    exibirLista(lista);

    excluirElemento(&lista, 10);
    printf("Quantidade de elementos na lista: %d\n", quantidadeElementos(lista));
    exibirLista(lista);

    alterarMatricula(&lista, 20, 25);
    printf("Quantidade de elementos na lista: %d\n", quantidadeElementos(lista));
    exibirLista(lista);

    liberarLista(&lista);

    return 0;
}
