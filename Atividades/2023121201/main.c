#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_dinamica.h"

int main()

{

LISTA_MATRICULA lista;

inicializar_lista(&lista);

ALUNO novoAluno1 = {1, "João", 20};
ALUNO novoAluno2 = {2, "Maria", 22};
ALUNO novoAluno3 = {3, "Jean", 25};


int inserirAluno(LISTA_MATRICULA* m, ALUNO novo_aluno);
inserirAluno(&lista, novoAluno1);
inserirAluno(&lista, novoAluno2);
inserirAluno(&lista, novoAluno3);

int inserirAlunoOrdenado(LISTA_MATRICULA* m, ALUNO novo_aluno);


mostrarLista_M(&lista);

lista_cheia (&lista);


}
