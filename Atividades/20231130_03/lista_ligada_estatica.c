#include "lista_ligada_estatica.h"
#include <stdio.h>

void inicializarLista(ListaLigadaEstatica *lista) {
    lista->tamanho = 0;
}

void imprimirLista(ListaLigadaEstatica *lista) {
    printf("Lista: ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

void permutarElementosA(ListaLigadaEstatica *lista) {
    if (lista->tamanho <= 1) {
        printf("A lista precisa ter pelo menos dois elementos para permutacao.\n");
        return;
    }

    int primeiroElemento = lista->dados[0];

    for (int i = 0; i < lista->tamanho - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->dados[lista->tamanho - 1] = primeiroElemento;
}

void permutarElementosB(ListaLigadaEstatica *lista) {
    if (lista->tamanho <= 1) {
        printf("A lista precisa ter pelo menos dois elementos para permutacao.\n");
        return;
    }

    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio < fim) {
        // Troca os elementos no início e no final da lista
        int temp = lista->dados[inicio];
        lista->dados[inicio] = lista->dados[fim];
        lista->dados[fim] = temp;

        inicio++;
        fim--;
    }
}
