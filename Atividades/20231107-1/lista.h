#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int *vetor;
    int quantidade;
} LISTA;

LISTA criarLista(int quantidade);
void liberarLista(LISTA *lista);
void inserirElemento(LISTA *lista, int elemento);
void inserirElementoOrdenado(LISTA *lista, int elemento);
void imprimirListaIterativo(LISTA lista);
int buscaBinariaRecursiva(LISTA lista, int elemento, int inicio, int fim);
void imprimirListaRecursivo(LISTA lista, int indice);
int buscarMaiorRecursivo(LISTA lista, int indice);
int buscarMenorRecursivo(LISTA lista, int indice);
int somaElementosRecursivo(LISTA lista, int indice);
int produtoElementosRecursivo(LISTA lista, int indice);

#endif
