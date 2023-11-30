#ifndef LISTA_LIGADA_ESTATICA_H
#define LISTA_LIGADA_ESTATICA_H

#define TAMANHO_LISTA 100

typedef struct {
    int dados[TAMANHO_LISTA];
    int tamanho;
} ListaLigadaEstatica;

void inicializarLista(ListaLigadaEstatica *lista);

void imprimirLista(ListaLigadaEstatica *lista);

void copiarLista(ListaLigadaEstatica *origem, ListaLigadaEstatica *destino);

void concatenarListas(ListaLigadaEstatica *l1, ListaLigadaEstatica *l2, ListaLigadaEstatica *resultado);

void intercalarListas(ListaLigadaEstatica *l1, ListaLigadaEstatica *l2, ListaLigadaEstatica *resultado);

#endif
