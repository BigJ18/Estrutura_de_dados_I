// aluno.h

#ifndef ALUNO_H
#define ALUNO_H

#define MAX_ALUNOS 100

typedef struct {
    int matricula;
} Aluno;

typedef struct {
    Aluno elementos[MAX_ALUNOS];
    int quantidade;
} ListaAlunos;

void inicializarLista(ListaAlunos *lista);
void liberarLista(ListaAlunos *lista);
int quantidadeElementos(ListaAlunos lista);
int listaCheia(ListaAlunos lista);
int listaVazia(ListaAlunos lista);
void exibirLista(ListaAlunos lista);
void inserirElementoOrdenado(ListaAlunos *lista, int matricula);
void excluirElemento(ListaAlunos *lista, int matricula);
void alterarMatricula(ListaAlunos *lista, int antigaMatricula, int novaMatricula);

#endif
