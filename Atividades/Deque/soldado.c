#include <stdio.h>
#include <stdlib.h>
#include "soldado.h"

Deque* criarDeque() {
    Deque *deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        printf("Erro ao alocar memória para o deque.\n");
        exit(EXIT_FAILURE);
    }

    deque->inicio = NULL;
    deque->fim = NULL;
    deque->tamanho = 0;

    return deque;
}

void destruirDeque(Deque *deque) {
    while (!vazia(deque)) {
        removerInicio(deque);
    }
    free(deque);
}

int inserirInicio(Deque *deque, Soldado x) {
    Node *novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novoNode->soldado = x;
    novoNode->anterior = NULL;
    novoNode->proximo = deque->inicio;

    if (vazia(deque)) {
        deque->fim = novoNode;
    } else {
        deque->inicio->anterior = novoNode;
    }

    deque->inicio = novoNode;
    deque->tamanho++;

    return 1; // Inserção bem-sucedida
}

int inserirFim(Deque *deque, Soldado x) {
    Node *novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novoNode->soldado = x;
    novoNode->anterior = deque->fim;
    novoNode->proximo = NULL;

    if (vazia(deque)) {
        deque->inicio = novoNode;
    } else {
        deque->fim->proximo = novoNode;
    }

    deque->fim = novoNode;
    deque->tamanho++;

    return 1; // Inserção bem-sucedida
}

Soldado removerInicio(Deque *deque) {
    if (!vazia(deque)) {
        Node *temp = deque->inicio;
        Soldado elementoRemovido = temp->soldado;

        deque->inicio = deque->inicio->proximo;

        if (deque->inicio == NULL) {
            deque->fim = NULL;
        } else {
            deque->inicio->anterior = NULL;
        }

        free(temp);
        deque->tamanho--;

        return elementoRemovido;
    } else {
        // Deque vazio, retorna um soldado inválido
        Soldado soldadoInvalido = {-1, "", -1};
        return soldadoInvalido;
    }
}

Soldado removerFim(Deque *deque) {
    if (!vazia(deque)) {
        Node *temp = deque->fim;
        Soldado elementoRemovido = temp->soldado;

        deque->fim = deque->fim->anterior;

        if (deque->fim == NULL) {
            deque->inicio = NULL;
        } else {
            deque->fim->proximo = NULL;
        }

        free(temp);
        deque->tamanho--;

        return elementoRemovido;
    } else {
        // Deque vazio, retorna um soldado inválido
        Soldado soldadoInvalido = {-1, "", -1};
        return soldadoInvalido;
    }
}

Soldado primeiro(Deque *deque) {
    if (!vazia(deque)) {
        return deque->inicio->soldado;
    } else {
        // Deque vazio, retorna um soldado inválido
        Soldado soldadoInvalido = {-1, "", -1};
        return soldadoInvalido;
    }
}

Soldado ultimo(Deque *deque) {
    if (!vazia(deque)) {
        return deque->fim->soldado;
    } else {
        // Deque vazio, retorna um soldado inválido
        Soldado soldadoInvalido = {-1, "", -1};
        return soldadoInvalido;
    }
}

int contar(Deque *deque) {
    return deque->tamanho;
}

int vazia(Deque *deque) {
    return deque->tamanho == 0;
}

Soldado removerPos(Deque *deque, int n) {
    if (n >= 1 && n <= deque->tamanho) {
        int i;
        Node *temp = deque->inicio;

        // Percorre até a posição n
        for (i = 1; i < n; i++) {
            temp = temp->proximo;
        }

        // Atualiza os ponteiros dos nós vizinhos
        if (temp->anterior != NULL) {
            temp->anterior->proximo = temp->proximo;
        } else {
            // Se é o primeiro nó
            deque->inicio = temp->proximo;
        }

        if (temp->proximo != NULL) {
            temp->proximo->anterior = temp->anterior;
        } else {
           
            // Se é o último nó
            deque->fim = temp->anterior;
        }

        Soldado elementoRemovido = temp->soldado;
        free(temp);
        deque->tamanho--;

        return elementoRemovido;
    } else {
        // Posição inválida, retorna um soldado inválido
        Soldado soldadoInvalido = {-1, "", -1};
        return soldadoInvalido;
    }
}
