#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

#define MAX_ALUNOS 100

typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

typedef struct {
    Aluno alunos[MAX_ALUNOS];
    int quantidade;
} ListaAlunos;

void inicializarLista(ListaAlunos *lista);

void liberarLista(ListaAlunos *lista);

int quantidadeElementos(ListaAlunos *lista);

int listaCheia(ListaAlunos *lista);

int listaVazia(ListaAlunos *lista);

void exibirLista(ListaAlunos *lista);

void inserirElemento(ListaAlunos *lista, Aluno aluno);

void excluirElemento(ListaAlunos *lista, int matricula);

void alterarMatricula(ListaAlunos *lista, int matriculaAtual, int novaMatricula);

#endif
