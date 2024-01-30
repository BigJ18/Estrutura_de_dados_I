#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da pilha
struct Node {
    int data;
    struct Node* next;
};

// Definição da estrutura da pilha
struct Pilha {
    struct Node* topo;
};

// Função para inicializar a pilha
void inicializarPilha(struct Pilha* pilha) {
    pilha->topo = NULL;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(struct Pilha* pilha) {
    return (pilha->topo == NULL);
}

// Função para empilhar um elemento
void push(struct Pilha* pilha, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->next = pilha->topo;
    pilha->topo = novoNo;
}

// Função para desempilhar um elemento
int pop(struct Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha está vazia. Não é possível desempilhar.\n");
        return -1; // Valor de sentinela indicando erro
    }

    struct Node* temp = pilha->topo;
    int valor = temp->data;
    pilha->topo = pilha->topo->next;

    free(temp);
    return valor;
}

// Função para imprimir a pilha
void imprimirPilha(struct Pilha* pilha) {
    struct Node* atual = pilha->topo;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

int main() {
    // Inicializando a pilha
    struct Pilha minhaPilha;
    inicializarPilha(&minhaPilha);

    // Empilhando elementos
    push(&minhaPilha, 1);
    push(&minhaPilha, 2);
    push(&minhaPilha, 3);

    printf("Pilha após empilhar: ");
    imprimirPilha(&minhaPilha);

    // Desempilhando elementos
    int elementoDesempilhado = pop(&minhaPilha);
    printf("Elemento desempilhado: %d\n", elementoDesempilhado);

    printf("Pilha após desempilhar: ");
    imprimirPilha(&minhaPilha);

    return 0;
}
