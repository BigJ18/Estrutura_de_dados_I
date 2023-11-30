// aluno.c
#include <stdio.h>
#include "aluno.h"

void inicializarLista(ListaAlunos *lista) {
    lista->quantidade = 0;
}

void liberarLista(ListaAlunos *lista) {
    lista->quantidade = 0;
}

int quantidadeElementos(ListaAlunos lista) {
    return lista.quantidade;
}

int listaCheia(ListaAlunos lista) {
    return lista.quantidade == MAX_ALUNOS;
}

int listaVazia(ListaAlunos lista) {
    return lista.quantidade == 0;
}

void exibirLista(ListaAlunos lista) {
    int i;
    printf("Elementos da lista: ");
    for (i = 0; i < lista.quantidade; i++) {
        printf("%d ", lista.elementos[i].matricula);
    }
    printf("\n");
}

void inserirElementoOrdenado(ListaAlunos *lista, int matricula) {
    if (listaCheia(*lista)) {
        printf("Erro: Lista cheia.\n");
        return;
    }

    int i = lista->quantidade - 1;
    while (i >= 0 && lista->elementos[i].matricula > matricula) {
        lista->elementos[i + 1] = lista->elementos[i];
        i--;
    }

    lista->elementos[i + 1].matricula = matricula;
    lista->quantidade++;
}

void excluirElemento(ListaAlunos *lista, int matricula) {
    int i = 0;
    while (i < lista->quantidade && lista->elementos[i].matricula != matricula) {
        i++;
    }

    if (i == lista->quantidade) {
        printf("Matricula %d nao encontrada na lista.\n", matricula);
        return;
    }

    for (; i < lista->quantidade - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }

    lista->quantidade--;
}

void alterarMatricula(ListaAlunos *lista, int antigaMatricula, int novaMatricula) {
    int i = 0;
    while (i < lista->quantidade && lista->elementos[i].matricula != antigaMatricula) {
        i++;
    }

    if (i == lista->quantidade) {
        printf("Matricula %d nao encontrada na lista.\n", antigaMatricula);
        return;
    }

    lista->elementos[i].matricula = novaMatricula;
}
