#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct Node {
    int data;
    struct Node* proximo;
};

// Função para inserir um elemento no início da lista
void inserirNoInicio(struct Node** cabeca, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
}

// Função para inserir um elemento no final da lista
void inserirNoFinal(struct Node** cabeca, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->proximo = NULL;

    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }

    struct Node* temp = *cabeca;
    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }

    temp->proximo = novoNo;
}

// Função para imprimir a lista
void imprimirLista(struct Node* no) {
    while (no != NULL) {
        printf("%d ", no->data);
        no = no->proximo;
    }
    printf("\n");
}

int main() {
    // Inicializando a lista vazia
    struct Node* cabeca = NULL;

    // Inserindo elementos no início
    inserirNoInicio(&cabeca, 3);
    inserirNoInicio(&cabeca, 2);
    inserirNoInicio(&cabeca, 1);

    printf("Lista após inserção no início: ");
    imprimirLista(cabeca);

    // Inserindo elementos no final
    inserirNoFinal(&cabeca, 4);
    inserirNoFinal(&cabeca, 5);

    printf("Lista após inserção no final: ");
    imprimirLista(cabeca);

    return 0;
}
