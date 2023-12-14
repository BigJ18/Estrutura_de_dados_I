#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_dinamica.h"

void inicializar_lista(LISTA_MATRICULA *m){

    m->inicio = NULL;

}

int tamanho (LISTA_MATRICULA *m){

    int tam=0;
    ELEMENTO* i = m->inicio;
    while (i != NULL) {
        tam++;
        i = i->proximo;
    }

    return tam;

}

void mostrarLista_M (LISTA_MATRICULA* m){

    printf("---------\n");
    ELEMENTO *i= m->inicio;
    while (i != NULL) {
        printf("Aluno: %d\n",i);
        printf("Codigo: %d\n",i->alun.cod_aluno);
        printf("Nome: %s\n",i->alun.nome);
        printf("Idade: %d\n",i->alun.idade);
        i = i->proximo;

        }

    }

ELEMENTO* buscaElem_e_Pred(LISTA_MATRICULA* m, int cod_al, ELEMENTO** pred){

    *pred=NULL;
    ELEMENTO* atual = m->inicio;
    while ((atual !=NULL) && (atual->alun.cod_aluno < cod_al)) {

        *pred = atual;
        atual = atual -> proximo;

    }
if ((atual !=NULL) && (atual->alun.cod_aluno == cod_al))
    return atual;
return NULL;

}

int inserirAluno(LISTA_MATRICULA* m, ALUNO novo_aluno) {

    int novo_cod = novo_aluno.cod_aluno;
    ELEMENTO * pred;
    ELEMENTO* i;
    i = buscaElem_e_Pred(m, novo_cod, &pred);
    if (i!=NULL)
        return 0;
    i = malloc (sizeof(ELEMENTO));
    i->alun = novo_aluno;
    if (pred==NULL){
        i->proximo = m->inicio;
        m->inicio = i;
    }else{
        i->proximo = pred ->proximo;
        pred->proximo = i;
    } return 1;

}

int inserirAlunoOrdenado(LISTA_MATRICULA* m, ALUNO novo_aluno) {
    int novo_cod = novo_aluno.cod_aluno;
    ELEMENTO *pred, *atual;
    atual = m->inicio;

    while ((atual != NULL) && (atual->alun.cod_aluno < novo_cod)) {
        pred = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && atual->alun.cod_aluno == novo_cod) {
        printf("Aluno com código %d já está na lista.\n", novo_cod);
        return 0;
    }

    ELEMENTO* novo_elemento = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    if (novo_elemento == NULL) {
        printf("Erro ao alocar memória.\n");
        return 0;
    }
    novo_elemento->alun = novo_aluno;

    if (pred == NULL) {
        novo_elemento->proximo = m->inicio;
        m->inicio = novo_elemento;
    } else {
        novo_elemento->proximo = pred->proximo;
        pred->proximo = novo_elemento;

    }

    return 1;
}

void reinicializar(LISTA_MATRICULA* m) {

ELEMENTO* apagar;
ELEMENTO* elem = m->inicio;
while (elem != NULL) {

    ELEMENTO* apagar = elem;
    elem = elem->proximo;
    free (apagar);

}
m->inicio = NULL;

}

int lista_cheia (LISTA_MATRICULA *m){
    LISTA_MATRICULA lista;
    if (lista.inicio = NULL){
        printf("A lista está vazia\n");
        }else{
        printf("A lista não está vazia");
        }


}

