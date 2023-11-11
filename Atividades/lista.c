#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

LISTA criarLista(int quantidade) {
    LISTA novaLista;
    novaLista.vetor = (int *)malloc(quantidade * sizeof(int));
    novaLista.quantidade = quantidade;
    return novaLista;
}

void liberarLista(LISTA *lista) {
    free(lista->vetor);
    lista->vetor = NULL;
    lista->quantidade = 0;
}

void inserirElemento(LISTA *lista, int elemento) {
    lista->vetor[lista->quantidade++] = elemento;
}

void inserirElementoOrdenado(LISTA *lista, int elemento) {
    int i = lista->quantidade - 1;
    while (i >= 0 && lista->vetor[i] > elemento) {
        lista->vetor[i + 1] = lista->vetor[i];
        i--;
    }
    lista->vetor[i + 1] = elemento;
    lista->quantidade++;
}

void imprimirListaIterativo(LISTA lista) {
    for (int i = 0; i < lista.quantidade; i++) {
        printf("%d ", lista.vetor[i]);
    }
    printf("\n");
}

int buscaBinariaRecursiva(LISTA lista, int elemento, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista.vetor[meio] == elemento) {
            return meio;
        } else if (lista.vetor[meio] < elemento) {
            return buscaBinariaRecursiva(lista, elemento, meio + 1, fim);
        } else {
            return buscaBinariaRecursiva(lista, elemento, inicio, meio - 1);
        }
    }
    return -1; // Elemento não encontrado
}

void imprimirListaRecursivo(LISTA lista, int indice) {
    if (indice < lista.quantidade) {
        printf("%d ", lista.vetor[indice]);
        imprimirListaRecursivo(lista, indice + 1);
    } else {
        printf("\n");
    }
}

int buscarMaiorRecursivo(LISTA lista, int indice) {
    if (indice == 0) {
        return lista.vetor[indice];
    } else {
        int maiorRestante = buscarMaiorRecursivo(lista, indice - 1);
        return (maiorRestante > lista.vetor[indice]) ? maiorRestante : lista.vetor[indice];
    }
}

int buscarMenorRecursivo(LISTA lista, int indice) {
    if (indice == 0) {
        return lista.vetor[indice];
    } else {
        int menorRestante = buscarMenorRecursivo(lista, indice - 1);
        return (menorRestante < lista.vetor[indice]) ? menorRestante : lista.vetor[indice];
    }
}

int somaElementosRecursivo(LISTA lista, int indice) {
    if (indice == 0) {
        return lista.vetor[indice];
    } else {
        return lista.vetor[indice] + somaElementosRecursivo(lista, indice - 1);
    }
}

int produtoElementosRecursivo(LISTA lista, int indice) {
    if (indice == 0) {
        return lista.vetor[indice];
    } else {
        return lista.vetor[indice] * produtoElementosRecursivo(lista, indice - 1);
    }
}
