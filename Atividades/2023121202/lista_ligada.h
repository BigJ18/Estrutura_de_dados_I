#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct ListaLigada {
    No* cabeca;
} ListaLigada;

ListaLigada* criarLista();
void inserirElemento(ListaLigada* lista, int elemento);
void imprimirLista(ListaLigada* lista);
ListaLigada* permutarA(ListaLigada* lista);
ListaLigada* permutarB(ListaLigada* lista);
ListaLigada* copiarLista(ListaLigada* lista);
ListaLigada* concatenarListas(ListaLigada* lista1, ListaLigada* lista2);
ListaLigada* intercalarListas(ListaLigada* lista1, ListaLigada* lista2);

#endif
