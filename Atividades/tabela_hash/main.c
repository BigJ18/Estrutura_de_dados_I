#include <stdio.h>
#include "paciente.h"

int main() {
    TabelaHash *tabela = criarTabelaHash(10);

    Paciente paciente1 = {1, "João", "12345678901", 25};
    Paciente paciente2 = {2, "Maria", "98765432101", 30};
    Paciente paciente3 = {3, "Pedro", "56789012301", 40};

    inserirPaciente(tabela, paciente1);
    inserirPaciente(tabela, paciente2);
    inserirPaciente(tabela, paciente3);

    int codigoBusca = 2;
    Paciente *pacienteEncontrado = buscarPaciente(tabela, codigoBusca);

    if (pacienteEncontrado != NULL) {
        printf("Paciente encontrado:\n");
        printf("Código: %d\nNome: %s\nCPF: %s\nIdade: %d\n", 
               pacienteEncontrado->codigo, pacienteEncontrado->nome, 
               pacienteEncontrado->cpf, pacienteEncontrado->idade);
    } else {
        printf("Paciente com código %d não encontrado.\n", codigoBusca);
    }

    int codigoRemocao = 1;
    int remocaoSucesso = removerPaciente(tabela, codigoRemocao);

    if (remocaoSucesso) {
        printf("Paciente com código %d removido com sucesso.\n", codigoRemocao);
