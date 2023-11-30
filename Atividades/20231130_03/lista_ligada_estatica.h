#ifndef LISTA_LIGADA_ESTATICA_H
#define LISTA_LIGADA_ESTATICA_H

#define TAMANHO_LISTA 100

typedef struct {
    int dados[TAMANHO_LISTA];
    int tamanho;
} ListaLigadaEstatica;

void inicializarLista(ListaLigadaEstatica *lista);

void imprimirLista(ListaLigadaEstatica *lista);

void permutarElementosA(ListaLigadaEstatica *lista);

void permutarElementosB(ListaLigadaEstatica *lista);

#endif
