// fila.h

#ifndef FILA_H
#define FILA_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Fila;

// Funções públicas
Fila* criarFila();
void enfileirar(Fila* fila, int valor);
int desenfileirar(Fila* fila);
int frente(Fila* fila);
int estaVazia(Fila* fila);
void esvaziarFila(Fila* fila);
void destruirFila(Fila* fila);

#endif // FILA_H
