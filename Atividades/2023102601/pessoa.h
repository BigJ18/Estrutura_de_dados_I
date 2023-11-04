#ifndef PESSOA_H
#define PESSOA_H

typedef struct {

    char nome[50];
    char data_nascimento[11];
    char cpf[15];

} Pessoa;


void preencherDados(Pessoa *pessoa, const char *nome, const char *data_nascimento, const char *cpf);

void imprimirDados(const Pessoa *pessoa);

#endif
