#ifndef LISTA_H
#define LISTA_H

#define TAMANHO_MAXIMO 100

struct ListaLinearSequencial {
    int lista[TAMANHO_MAXIMO];
    int tamanho_atual;
};

void inicializarLista(struct ListaLinearSequencial *lista);
int estaCheia(struct ListaLinearSequencial *lista);
int estaVazia(struct ListaLinearSequencial *lista);
void adicionarElemento(struct ListaLinearSequencial *lista, int elemento);

#endif
