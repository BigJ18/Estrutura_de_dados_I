#include <stdio.h>
#include "pessoa.h"

int main() {
    Data dataNascimento;
    preencherData(&dataNascimento, 18, 04, 2004);

    Pessoa pessoa;
    preencherPessoa(&pessoa, "Jean Miguel", "123.456.789-00", &dataNascimento);

    printf("Dados da Pessoa:\n");
    imprimirPessoa(&pessoa);

    return 0;
}
