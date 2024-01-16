#include <stdio.h>
#include <stdlib.h>
#include "hangar.h"

void inicializarHangar(Hangar *hangar, int capacidade) {
    hangar->avioes = (Aviao *)malloc(capacidade * sizeof(Aviao));
    hangar->capacidade = capacidade;
    hangar->topo = -1;
}

void destruirHangar(Hangar *hangar) {
    free(hangar->avioes);
}

void adicionarAviao(Hangar *hangar, Aviao aviao) {
    if (hangar->topo < hangar->capacidade - 1) {
        hangar->topo++;
        hangar->avioes[hangar->topo] = aviao;
        printf("Aviao adicionado com sucesso.\n");
    } else {
        printf("Hangar cheio. Impossível adicionar mais aviões.\n");
    }
}

void removerAviao(Hangar *hangar) {
    if (hangar->topo >= 0) {
        printf("Aviao removido: %s\n", hangar->avioes[hangar->topo].nome);
        hangar->topo--;
    } else {
        printf("Hangar vazio. Impossível remover avião.\n");
    }
}

void listarAvioes(Hangar *hangar) {
    printf("Aviões no hangar:\n");
    for (int i = 0; i <= hangar->topo; i++) {
        printf("%s (ID: %d)\n", hangar->avioes[i].nome, hangar->avioes[i].identificador);
    }
}

void listarPrimeiroAviao(Hangar *hangar) {
    if (hangar->topo >= 0) {
        printf("Primeiro aviao no hangar:\n");
        printf("%s (ID: %d)\n", hangar->avioes[0].nome, hangar->avioes[0].identificador);
    } else {
        printf("Hangar vazio. Nenhum avião para listar.\n");
    }
}

int contarAvioes(Hangar *hangar) {
    return hangar->topo + 1;
}

void removerAviaoPorPosicao(Hangar *hangar, int posicao) {
    if (posicao <= hangar->topo && posicao >= 0) {
        printf("Removendo aviao na posição %d: %s\n", posicao, hangar->avioes[posicao].nome);
        for (int i = posicao; i < hangar->topo; i++) {
            hangar->avioes[i] = hangar->avioes[i + 1];
        }
        hangar->topo--;
    } else {
        printf("Posição inválida. Não foi possível remover o avião.\n");
    }
}
