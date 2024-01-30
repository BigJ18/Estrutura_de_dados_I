#include <stdio.h>

// Definição da estrutura do nó
struct Node {
    int data;
    int proximo;  // Índice do próximo nó no array
};

#define MAX_NODES 100  // Tamanho máximo da lista ligada estática

// Função para inicializar a lista
void inicializarLista(struct Node lista[], int* cabeca) {
    *cabeca = -1;  // Lista vazia
}

// Função para inserir um elemento no início da lista
void inserirNoInicio(struct Node lista[], int* cabeca, int valor) {
    if (*cabeca == -1) {
        // Lista vazia, criando o primeiro nó
        lista[0].data = valor;
        lista[0].proximo = -1;
        *cabeca = 0;
    } else {
        // Encontrar um espaço livre no array
        int novoIndice = 0;
        while (lista[novoIndice].proximo != -1) {
            novoIndice++;
        }

        // Criar um novo nó
        lista[novoIndice].data = valor;
        lista[novoIndice].proximo = *cabeca;

        // Atualizar o cabeçalho
        *cabeca = novoIndice;
    }
}

// Função para imprimir a lista
void imprimirLista(struct Node lista[], int cabeca) {
    int indiceAtual = cabeca;
    while (indiceAtual != -1) {
        printf("%d ", lista[indiceAtual].data);
        indiceAtual = lista[indiceAtual].proximo;
    }
    printf("\n");
}

int main() {
    struct Node lista[MAX_NODES];
    int cabeca;

    // Inicializando a lista
    inicializarLista(lista, &cabeca);

    // Inserindo elementos no início
    inserirNoInicio(lista, &cabeca, 3);
    inserirNoInicio(lista, &cabeca, 2);
    inserirNoInicio(lista, &cabeca, 1);

    printf("Lista após inserção no início: ");
    imprimirLista(lista, cabeca);

    return 0;
}
