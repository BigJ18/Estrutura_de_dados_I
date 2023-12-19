#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

ListaLigada* criarLista() {
    ListaLigada* novaLista = (ListaLigada*)malloc(sizeof(ListaLigada));
    novaLista->cabeca = NULL;
    return novaLista;
}

void inserirElemento(ListaLigada* lista, int elemento) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = elemento;
    novoNo->proximo = lista->cabeca;
    lista->cabeca = novoNo;
}

void imprimirLista(ListaLigada* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

ListaLigada* permutarA(ListaLigada* lista) {
    ListaLigada* novaLista = criarLista();
    No* atual = lista->cabeca;

    while (atual->proximo != NULL) {
        inserirElemento(novaLista, atual->proximo->dado);
        atual = atual->proximo;
    }

    inserirElemento(novaLista, lista->cabeca->dado);

    return novaLista;
}

ListaLigada* permutarB(ListaLigada* lista) {
    ListaLigada* novaLista = criarLista();
    No* atual = lista->cabeca;

    while (atual != NULL) {
        inserirElemento(novaLista, atual->dado);
        atual = atual->proximo;
    }

    return novaLista;
}

ListaLigada* copiarLista(ListaLigada* lista) {
    ListaLigada* novaLista = criarLista();
    No* atual = lista->cabeca;

    while (atual != NULL) {
        inserirElemento(novaLista, atual->dado);
        atual = atual->proximo;
    }

    return novaLista;
}

ListaLigada* concatenarListas(ListaLigada* lista1, ListaLigada* lista2) {
    ListaLigada*
