#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
struct Node {
    int data;
    struct Node* proximo;
};

// Definição da estrutura da fila
struct Fila {
    struct Node* inicio;
    struct Node* fim;
};

// Função para inicializar a fila
void inicializarFila(struct Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Função para verificar se a fila está vazia
int filaVazia(struct Fila* fila) {
    return (fila->inicio == NULL);
}

// Função para enfileirar um elemento
void enfileirar(struct Fila* fila, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

// Função para desenfileirar um elemento
int desenfileirar(struct Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia. Não é possível desenfileirar.\n");
        return -1; // Valor de sentinela indicando erro
    }

    struct Node* temp = fila->inicio;
    int valor = temp->data;

    if (fila->inicio == fila->fim) {
        // Único elemento na fila
        fila->inicio = NULL;
        fila->fim = NULL;
    } else {
        fila->inicio = fila->inicio->proximo;
    }

    free(temp);
    return valor;
}

// Função para imprimir a fila
void imprimirFila(struct Fila* fila) {
    struct Node* atual = fila->inicio;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    // Inicializando a fila
    struct Fila minhaFila;
    inicializarFila(&minhaFila);

    // Enfileirando elementos
    enfileirar(&minhaFila, 1);
    enfileirar(&minhaFila, 2);
    enfileirar(&minhaFila, 3);

    printf("Fila após enfileirar: ");
    imprimirFila(&minhaFila);

    // Desenfileirando elementos
    int elementoDesenfileirado = desenfileirar(&minhaFila);
    printf("Elemento desenfileirado: %d\n", elementoDesenfileirado);

    printf("Fila após desenfileirar: ");
    imprimirFila(&minhaFila);

    return 0;
}
