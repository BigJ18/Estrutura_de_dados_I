#include <stdio.h>
#include "pessoa.h"

int main() {
    Data dataNascimento;
    Pessoa pessoa;

    preencherData(&dataNascimento, 1, 1, 1980);
    preencherPessoa(&pessoa, "Joao da Silva", dataNascimento, "123.456.789-00");

    printf("Dados da Pessoa:\n");
    imprimirPessoa(&pessoa);

    return 0;
}
