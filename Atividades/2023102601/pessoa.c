#include <stdio.h>
#include <string.h>
#include "pessoa.h"

void preencherDados(Pessoa *pessoa, const char *nome, const char *data_nascimento, const char *cpf) {

    strncpy(pessoa->nome, nome, sizeof(pessoa->nome));
    strncpy(pessoa->data_nascimento, data_nascimento, sizeof(pessoa->data_nascimento));
    strncpy(pessoa->cpf, cpf, sizeof(pessoa->cpf));

}

void imprimirDados(const Pessoa *pessoa) {

    printf("Nome: %s\n", pessoa->nome);
    printf("Data de Nascimento: %s\n", pessoa->data_nascimento);
    printf("CPF: %s\n", pessoa->cpf);

}
