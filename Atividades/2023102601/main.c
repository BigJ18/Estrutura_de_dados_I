#include <stdio.h>
#include "pessoa.h"

int main() {

    Pessoa pessoa1;
    Pessoa *ponteiroPessoa = &pessoa1;

    preencherDados(ponteiroPessoa, "Jean Miguel", "18/04/2004", "065.419.012-79");

    printf("Dados da Pessoa:\n");
    imprimirDados(ponteiroPessoa);

    return 0;
}

