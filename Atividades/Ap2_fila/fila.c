// fila.c

#include "fila.h"
#include <stdlib.h>

Fila* criarFila() {
    Fila* novaFila = (Fila*)malloc(sizeof(Fila));
    if (novaFila == NULL) {
        // Tratar erro de alocação de memória
        exit(EXIT_FAILURE);
    }
    novaFila->front = novaFila->rear = NULL;
    return novaFila;
}

void enfileirar(Fila* fila, int valor) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        // Tratar erro de alocação de memória
        exit(EXIT_FAILURE);
    }
    novoNode->data = valor;
    novoNode->next = NULL;

    if (fila->rear == NULL) {
        fila->front = fila->rear = novoNode;
    } else {
        fila->rear->next = novoNode;
        fila->rear = novoNode;
    }
}

int desenfileirar(Fila* fila) {
    if (fila->front == NULL) {
        // Tratar fila vazia
        exit(EXIT_FAILURE);
    }

    Node* temp = fila->front;
    int valor = temp->data;

    fila->front = fila->front->next;

    if (fila->front == NULL) {
        fila->rear = NULL;
    }

    free(temp);
    return valor;
}

int frente(Fila* fila) {
    if (fila->front == NULL) {
        // Tratar fila vazia
        exit(EXIT_FAILURE);
    }
    return fila->front->data;
}

int estaVazia(Fila* fila) {
    return fila->front == NULL;
}

void esvaziarFila(Fila* fila) {
    while (!estaVazia(fila)) {
        desenfileirar(fila);
    }
}

void destruirFila(Fila* fila) {
    esvaziarFila(fila);
    free(fila);
}
