#ifndef PESSOA_H
#define PESSOA_H
#include "data.h"

typedef struct {
    char nome[50];
    Data dataNascimento;
    char cpf[15];
} Pessoa;

void preencherPessoa(Pessoa *pessoa, const char *nome, const char *cpf, Data *dataNascimento);
void imprimirPessoa(Pessoa *pessoa);

#endif
