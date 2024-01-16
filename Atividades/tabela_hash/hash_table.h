#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct {
    int codigo;
    char nome[50];
    char cpf[12];
    int idade;
} Paciente;

typedef struct Node {
    Paciente paciente;
    struct Node *proximo;
} Node;

typedef struct {
    Node **tabela;
    int tamanho;
} HashTable;

// Inicializa a tabela hash com o tamanho especificado
HashTable* inicializarHashTable(int tamanho);

// Libera a memória alocada para a tabela hash
void destruirHashTable(HashTable *hashTable);

// Insere um paciente na tabela hash
void inserirPaciente(HashTable *hashTable, Paciente paciente);

// Remove um paciente da tabela hash pelo código
void removerPaciente(HashTable *hashTable, int codigo);

// Busca um paciente na tabela hash pelo código
Paciente buscarPaciente(HashTable *hashTable, int codigo);

// Função de hash simples para este exemplo
int calcularHash(int codigo, int tamanho);

#endif // HASH_TABLE_H
