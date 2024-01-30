#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct Node {
    int data;
    struct Node* proximo;
    struct Node* anterior;
};

// Função para inserir um elemento no início da lista
void inserirNoInicio(struct Node** cabeca, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->proximo = *cabeca;
    novoNo->anterior = NULL;

    if (*cabeca != NULL) {
        (*cabeca)->anterior = novoNo;
    }

    *cabeca = novoNo;
}

// Função para imprimir a lista do início ao fim
void imprimirLista(struct Node* cabeca) {
    while (cabeca != NULL) {
        printf("%d ", cabeca->data);
        cabeca = cabeca->proximo;
    }
    printf("\n");
}

// Função para imprimir a lista do fim ao início
void imprimirListaReversa(struct Node* cabeca) {
    while (cabeca != NULL) {
        printf("%d ", cabeca->data);
        cabeca = cabeca->anterior;
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

    printf("Lista do início ao fim: ");
    imprimirLista(cabeca);

    printf("Lista do fim ao início: ");
    imprimirListaReversa(cabeca);

    return 0;
}
