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

void copiarLista(ListaLigadaEstatica *origem, ListaLigadaEstatica *destino) {
    destino->tamanho = origem->tamanho;
    for (int i = 0; i < origem->tamanho; i++) {
        destino->dados[i] = origem->dados[i];
    }
}

void concatenarListas(ListaLigadaEstatica *l1, ListaLigadaEstatica *l2, ListaLigadaEstatica *resultado) {
    resultado->tamanho = 0;

    for (int i = 0; i < l1->tamanho; i++) {
        resultado->dados[resultado->tamanho++] = l1->dados[i];
    }

    for (int i = 0; i < l2->tamanho; i++) {
        resultado->dados[resultado->tamanho++] = l2->dados[i];
    }
}

void intercalarListas(ListaLigadaEstatica *l1, ListaLigadaEstatica *l2, ListaLigadaEstatica *resultado) {
    resultado->tamanho = 0;

    int i = 0, j = 0;

    while (i < l1->tamanho || j < l2->tamanho) {
        if (i < l1->tamanho) {
            resultado->dados[resultado->tamanho++] = l1->dados[i];
            i++;
        }

        if (j < l2->tamanho) {
            resultado->dados[resultado->tamanho++] = l2->dados[j];
            j++;
        }
    }
}
