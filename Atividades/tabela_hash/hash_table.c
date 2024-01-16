#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

HashTable* inicializarHashTable(int tamanho) {
    HashTable *hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        printf("Erro ao alocar memória para a tabela hash.\n");
        exit(EXIT_FAILURE);
    }

    hashTable->tamanho = tamanho;
    hashTable->tabela = (Node**)calloc(tamanho, sizeof(Node*));

    return hashTable;
}

void destruirHashTable(HashTable *hashTable) {
    for (int i = 0; i < hashTable->tamanho; i++) {
        Node *atual = hashTable->tabela[i];
        while (atual != NULL) {
            Node *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    free(hashTable->tabela);
    free(hashTable);
}

void inserirPaciente(HashTable *hashTable, Paciente paciente) {
    int indice = calcularHash(paciente.codigo, hashTable->tamanho);

    Node *novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novoNode->paciente
