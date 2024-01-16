#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    int codigo;
    char nome[50];
    char cpf[15];
    int idade;
} Paciente;

typedef struct Node {
    Paciente paciente;
    struct Node *prox;
} Node;

typedef struct {
    Node *head;
} Lista;

typedef struct {
    int tamanho;
    int capacidade;
    Lista *tabela;
} TabelaHash;

TabelaHash* criarTabelaHash(int capacidade);
void destruirTabelaHash(TabelaHash *tabela);
int hash(int codigo, int capacidade);
int inserirPaciente(TabelaHash *tabela, Paciente paciente);
Paciente* buscarPaciente(TabelaHash *tabela, int codigo);
int removerPaciente(TabelaHash *tabela, int codigo);

#endif // PACIENTE_H
