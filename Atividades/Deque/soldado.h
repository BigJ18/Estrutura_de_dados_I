#ifndef SOLDADO_H
#define SOLDADO_H

typedef struct {
    int codigo;
    char nome[50];
    int grau;
} Soldado;

typedef struct Node {
    Soldado soldado;
    struct Node *anterior;
    struct Node *proximo;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
    int tamanho;
} Deque;

Deque* criarDeque();
void destruirDeque(Deque *deque);

int inserirInicio(Deque *deque, Soldado x);
int inserirFim(Deque *deque, Soldado x);
Soldado removerInicio(Deque *deque);
Soldado removerFim(Deque *deque);
Soldado primeiro(Deque *deque);
Soldado ultimo(Deque *deque);
int contar(Deque *deque);
int vazia(Deque *deque);
Soldado removerPos(Deque *deque, int n);

#endif // SOLDADO_H
