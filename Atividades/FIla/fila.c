#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int identificador;
} Aviao;

typedef struct No {
    Aviao aviao;
    struct No* proximo;
} No;

typedef struct {
    No* frente;
    No* tras;
} FilaDecolagem;

void inicializarFila(FilaDecolagem* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

int filaVazia(FilaDecolagem* fila) {
    return fila->frente == NULL;
}

void enfileirar(FilaDecolagem* fila, Aviao aviao) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->aviao = aviao;
    novoNo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->frente = novoNo;
        fila->tras = novoNo;
    } else {
        fila->tras->proximo = novoNo;
        fila->tras = novoNo;
    }
}

Aviao desenfileirar(FilaDecolagem* fila

) {
    Aviao aviaoDecolagem;

    if (filaVazia(fila)) {
        printf("Nao ha avioes na fila de decolagem.\n");
        aviaoDecolagem.identificador = -1;
        return aviaoDecolagem;
    }

    No* noRemovido = fila->frente;
    aviaoDecolagem = noRemovido->aviao;

    if (fila->frente == fila->tras) {
        fila->frente = NULL;
        fila->tras = NULL;
    } else {
        fila->frente = fila->frente->proximo;
    }

    free(noRemovido);
    return aviaoDecolagem;
}

void listarNumeroAvioes(FilaDecolagem* fila) {
    printf("Total de avioes aguardando na fila: %d\n", filaVazia(fila) ? 0 : 1);
}

void autorizarDecolagem(FilaDecolagem* fila) {
    Aviao aviao = desenfileirar(fila);
    if (aviao.identificador != -1) {
        printf("Autorizando decolagem do aviao %s (ID: %d)\n", aviao.nome, aviao.identificador);
    }
}

void adicionarAviao(FilaDecolagem* fila, Aviao aviao) {
    enfileirar(fila, aviao);
    printf("Aviao %s (ID: %d) adicionado a fila de espera.\n", aviao.nome, aviao.identificador);
}

void listarAvioesEspera(FilaDecolagem* fila) {
    printf("Avioes na fila de espera:\n");

    No* atual = fila->frente;
    while (atual != NULL) {
        printf("%s (ID: %d)\n", atual->aviao.nome, atual->aviao.identificador);
        atual = atual->proximo;
    }
}

void listarCaracteristicasPrimeiroAviao(FilaDecolagem* fila) {
    if (!filaVazia(fila)) {
        printf("Caracteristicas do primeiro aviao na fila:\n");
        printf("Nome: %s\n", fila->frente->aviao.nome);
        printf("ID: %d\n", fila->frente->aviao.identificador);
    } else {
        printf("Nao ha avioes na fila de decolagem.\n");
    }
}

int main() {
    FilaDecolagem fila;
    inicializarFila(&fila);

    Aviao aviao1 = {"Boeing 737", 1};
    Aviao aviao2 = {"Airbus A320", 2};
    Aviao aviao3 = {"Embraer E190", 3};

    adicionarAviao(&fila, aviao1);
    adicionarAviao(&fila, aviao2);
    adicionarAviao(&fila, aviao3);

    listarNumeroAvioes(&fila);
    listarAvioesEspera(&fila);
    listarCaracteristicasPrimeiroAviao(&fila);

    autorizarDecolagem(&fila);
    listarNumeroAvioes(&fila);

    return 0;
}

