#include <stdio.h>
#include "pessoa.h"

int main() {
    Data dataNascimento;
    Pessoa pessoa;

    preencherData(&dataNascimento, 18, 04, 2004);
    preencherPessoa(&pessoa, "Jean Miguel", dataNascimento, "065.419.012-79");

    printf("Dados da Pessoa:\n");
    imprimirPessoa(&pessoa);

    return 0;
}
