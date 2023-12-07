#include "lista.h"
#include <stdio.h>

void inicializarLista(struct ListaLinearSequencial *lista) {
    lista->tamanho_atual = 0;
}

int estaCheia(struct ListaLinearSequencial *lista) {
    return lista->tamanho_atual == TAMANHO_MAXIMO;
}

int estaVazia(struct ListaLinearSequencial *lista) {
    return lista->tamanho_atual == 0;
}

void adicionarElemento(struct ListaLinearSequencial *lista, int elemento) {
    if (estaCheia(lista)) {
        printf("A lista está cheia. Não é possível adicionar mais elementos.\n");
    } else {
        lista->lista[lista->tamanho_atual] = elemento;
        lista->tamanho_atual++;
    }
}
