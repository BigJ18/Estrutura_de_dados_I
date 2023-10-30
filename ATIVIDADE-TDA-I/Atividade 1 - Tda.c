#include <stdio.h>
#include "pessoa.h"

void preencherData(Data* data, int dia, int mes, int ano) {
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void imprimirData(const Data* data) {
    printf("%02d/%02d/%04d\n", data->dia, data->mes, data->ano);
}

void preencherPessoa(Pessoa* pessoa, const char* nome, Data dataNascimento, const char* cpf) {
    snprintf(pessoa->nome, sizeof(pessoa->nome), "%s", nome);
    pessoa->dataNascimento = dataNascimento;
    snprintf(pessoa->cpf, sizeof(pessoa->cpf), "%s", cpf);
}

void imprimirPessoa(const Pessoa* pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de Nascimento: ");
    imprimirData(&(pessoa->dataNascimento));
    printf("CPF: %s\n", pessoa->cpf);
}
