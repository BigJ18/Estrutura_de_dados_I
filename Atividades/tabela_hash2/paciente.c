#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

TabelaHash* criarTabelaHash(int capacidade) {
    TabelaHash *tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    if (tabela == NULL) {
        printf("Erro ao alocar memória para a tabela hash.\n");
        exit(EXIT_FAILURE);
    }

    tabela->tamanho = 0;
    tabela->capacidade = capacidade;

    tabela->tabela = (Lista*)malloc(capacidade * sizeof(Lista));
    if (tabela->tabela == NULL) {
        printf("Erro ao alocar memória para a array da tabela hash.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < capacidade; i++) {
        tabela->tabela[i].head = NULL;
    }

    return tabela;
}

void destruirTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < tabela->capacidade; i++) {
        Node *atual = tabela->tabela[i].head;
        while (atual != NULL) {
            Node *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }

    free(tabela->tabela);
    free(tabela);
}

int hash(int codigo, int capacidade) {
    return codigo % capacidade;
}

int inserirPaciente(TabelaHash *tabela, Paciente paciente) {
    int indice = hash(paciente.codigo, tabela->capacidade);

    Node *novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novoNode->paciente = paciente;
    novoNode->prox = tabela->tabela[indice].head;
    tabela->tabela[indice].head = novoNode;

    tabela->tamanho++;

    return 1; // Inserção bem-sucedida
}

Paciente* buscarPaciente(TabelaHash *tabela, int codigo) {
    int indice = hash(codigo, tabela->capacidade);

    Node *atual = tabela->tabela[indice].head;
    while (atual != NULL) {
        if (atual->paciente.codigo == codigo) {
            return &(atual->paciente);
        }
        atual = atual->prox;
    }

    return NULL; // Paciente não encontrado
}

int removerPaciente(TabelaHash *tabela, int codigo) {
    int indice = hash(codigo, tabela->capacidade);

    Node *atual = tabela->tabela[indice].head;
    Node *anterior = NULL;

    while (atual != NULL) {
        if (atual->paciente.codigo == codigo) {
            if (anterior != NULL) {
                anterior->prox = atual->prox;
            } else {
                tabela->tabela[indice].head = atual->prox;
            }

            free(atual);
            tabela->tamanho--;

            return 1; // Remoção bem-sucedida
        }

        anterior = atual;
        atual = atual->prox;
    }

int excluirPaciente(TabelaHash *tabela, int codigo) {
    int indice = hash(codigo, tabela->capacidade);

    Node *atual = tabela->tabela[indice].head;
    Node *anterior = NULL;

    while (atual != NULL) {
        if (atual->paciente.codigo == codigo) {
            if (anterior != NULL) {
                anterior->prox = atual->prox;
            } else {
                tabela->tabela[indice].head = atual->prox;
            }

            free(atual);
            tabela->tamanho--;

            return 1; // Exclusão bem-sucedida
        }

        anterior = atual;
        atual = atual->prox;
    }

    return 0; // Paciente não encontrado para exclusão
}

