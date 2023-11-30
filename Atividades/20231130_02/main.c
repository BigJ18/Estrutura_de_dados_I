#include "lista_alunos.h"

int main() {
    ListaAlunos turma;
    inicializarLista(&turma);

    Aluno aluno1 = {101, "Joao", 20};
    Aluno aluno2 = {105, "Maria", 22};
    Aluno aluno3 = {103, "Carlos", 21};

    inserirElemento(&turma, aluno1);
    inserirElemento(&turma, aluno2);
    inserirElemento(&turma, aluno3);

    printf("Quantidade de elementos na lista: %d\n", quantidadeElementos(&turma));
    printf("Lista cheia: %s\n", listaCheia(&turma) ? "Sim" : "Nao");
    printf("Lista vazia: %s\n", listaVazia(&turma) ? "Sim" : "Nao");

    printf("\nExibindo elementos da lista:\n");
    exibirLista(&turma);

    printf("\nExcluindo elemento com matricula 105:\n");
    excluirElemento(&turma, 105);
    exibirLista(&turma);

    printf("\nAlterando matricula 103 para 110:\n");
    alterarMatricula(&turma, 103, 110);
    exibirLista(&turma);

    liberarLista(&turma);

    return 0;
}
