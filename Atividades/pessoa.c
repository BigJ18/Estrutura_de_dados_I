#include <stdio.h>
#include "pessoa.h"

void preencherPessoa(Pessoa *pessoa, const char *nome, const char *cpf, Data *dataNascimento) {
    snprintf(pessoa->nome, sizeof(pessoa->nome), "%s", nome);
    snprintf(pessoa->cpf, sizeof(pessoa->cpf), "%s", cpf);
    pessoa->dataNascimento = *dataNascimento;
}

void imprimirPessoa(Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de Nascimento: ");
    imprimirData(&pessoa->dataNascimento);
    printf("CPF: %s\n", pessoa->cpf);
}
