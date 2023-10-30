#ifndef PESSOA_H
#define PESSOA_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    Data dataNascimento;
    char cpf[12];
} Pessoa;

void preencherData(Data* data, int dia, int mes, int ano);
void imprimirData(const Data* data);

void preencherPessoa(Pessoa* pessoa, const char* nome, Data dataNascimento, const char* cpf);
void imprimirPessoa(const Pessoa* pessoa);

#endif
