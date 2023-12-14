#ifndef LISTA_LIGADA_DINAMICA_H_INCLUDED
#define LISTA_LIGADA_DINAMICA_H_INCLUDED

typedef struct {

int cod_aluno;
char *nome;
int idade;
int n_filhos;

}ALUNO;

typedef struct aux {

    ALUNO alun;
    struct aux *proximo;
}ELEMENTO;


typedef struct {

ELEMENTO *inicio;

}LISTA_MATRICULA;


void inicializar_lista(LISTA_MATRICULA *m);

int tamanho (LISTA_MATRICULA *m);

void mostrarLista_M (LISTA_MATRICULA* m);

int inserirAluno(LISTA_MATRICULA* m, ALUNO novo_aluno);

ELEMENTO* buscaElem_e_Pred(LISTA_MATRICULA* m, int cod_al, ELEMENTO** pred);

void reinicializar(LISTA_MATRICULA* m);

int lista_cheia (LISTA_MATRICULA *m);

int inserirAlunoOrdenado(LISTA_MATRICULA* m, ALUNO novo_aluno);

#endif // LISTA_LIGADA_DINAMICA_H_INCLUDED
