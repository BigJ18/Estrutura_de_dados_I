#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct {
    char nome[50];
    int elemento;

} Numeros;

typedef struct {
    Numeros *numeros;
    int capacidade;
    int topo;
} PILHA;

typedef struct {
    char nome2[50];
    int elemento2;

} Numeros2;

typedef struct {
    Numeros2 *numeros2;
    int capacidade2;
    int topo2;
} PILHA2;

typedef struct {
    int capacidade;
    int inicio;
    int fim;
}FILA;


void inicializarFila(FILA *fila){

    fila->inicio = -1;
    fila->fim = -1;

}

void push_fila(FILA *fila, int elementos){



}



void inicializarPilha(PILHA *pilha, int capacidade) {
    pilha->numeros = (Numeros *)malloc(capacidade * sizeof(Numeros));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
}


void push_pilha(PILHA *pilha, Numeros numeros) {
    if (pilha->topo < pilha->capacidade - 1) {
        pilha->topo++;
        pilha->numeros[pilha->topo] = numeros;
    } else {
        printf("pilha cheia. Impossível adicionar mais elementos.\n");
    }
}

void pop_pilha(PILHA *pilha) {
    if (pilha->topo >= 0) {
        printf("elemento removido %s\n", pilha->numeros[pilha->topo].nome);
        pilha->topo--;
    } else {
        printf("Pilha cheia. Impossível adicionar mais elementos.\n");
    }
}

void imprimir_pilha1(PILHA *pilha) {
    printf("elementos na pilha1:\n");
    for (int i = 0; i <= pilha->topo; i++) {
        printf("%d \n", pilha->numeros[i]);
    }
}



void inicializarPilha2(PILHA2 *pilha2, int capacidade2) {
    pilha2->numeros2 = (Numeros2 *)malloc(capacidade2 * sizeof(Numeros2));
    pilha2->capacidade2 = capacidade2;
    pilha2->topo2 = -1;
}


void push_pilha2(PILHA2 *pilha2, Numeros2 numeros2) {
    if (pilha2->topo2 < pilha2->capacidade2 - 1) {
        pilha2->topo2++;
        pilha2->numeros2[pilha2->topo2] = numeros2;
    } else {
        printf("Pilha cheia. Impossível adicionar mais elementos.\n");
    }
}

void pop_pilha2(PILHA2 *pilha2) {
    if (pilha2->topo2 >= 0) {
        printf("Aviao removido: %s\n", pilha2->numeros2[pilha2->topo2].nome2);
        pilha2->topo2--;
    } else {
        printf("Pilha cheia. impossível remover");
    }
}

void imprimir_pilha2(PILHA2 *pilha2) {
    printf("elementos na pilha2:\n");
    for (int i = 0; i <= pilha2->topo2; i++) {
    printf("%d \n", pilha2->numeros2[i]);
    }
}


int main() {

    time_t now;
    time(&now);
    printf("Data e hora de entrega %s\n", ctime(&now));
    printf("Jean Miguel Conceiçao Brito\n");
    printf("Numero do exercicio: 003\n");

    PILHA p;
    PILHA2 p2;

    inicializarPilha(&p, 10);
    inicializarPilha2(&p2, 10);

    Numeros numero1 = {7};
    Numeros numero2 = {5};
    Numeros numero3 = {4};
    Numeros numero4 = {3};
    Numeros numero5 = {1};

    Numeros2 numero6 = {8};
    Numeros2 numero7 = {6};
    Numeros2 numero8 = {4};
    Numeros2 numero9 = {1};

    push_pilha(&p, numero1);
    push_pilha(&p, numero2);
    push_pilha(&p, numero3);
    push_pilha(&p, numero4);
    push_pilha(&p, numero5);

    push_pilha2(&p2, numero6);
    push_pilha2(&p2, numero7);
    push_pilha2(&p2, numero8);
    push_pilha2(&p2, numero9);

    imprimir_pilha1(&p);

    imprimir_pilha2(&p2);


}
