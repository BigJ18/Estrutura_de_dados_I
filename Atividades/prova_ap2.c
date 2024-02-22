#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* direita, *esquerda;
} NoArv;

NoArv* inserir_versao_1(NoArv* raiz, int num) {
    if (raiz == NULL) {
        NoArv* aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    } else {
        if (num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

NoArv* buscar(NoArv* raiz, int chave) {
    if (raiz == NULL || raiz->valor == chave) {
        return raiz;
    }

    if (chave < raiz->valor) {
        return buscar(raiz->esquerda, chave);
    } else {
        return buscar(raiz->direita, chave);
    }
}

NoArv* encontrarMinimo(NoArv* raiz) {
    NoArv* atual = raiz;

    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual;
}

NoArv* retirar(NoArv* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }

    if (chave < raiz->valor) {
        raiz->esquerda = retirar(raiz->esquerda, chave);
    } else if (chave > raiz->valor) {
        raiz->direita = retirar(raiz->direita, chave);
    } else {
        if (raiz->esquerda == NULL) {
            NoArv* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            NoArv* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        NoArv* temp = encontrarMinimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = retirar(raiz->direita, temp->valor);
    }

    return raiz;
}

void imprimirEmOrdem(NoArv* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

int main() {
    NoArv* raiz = NULL;

    raiz = inserir_versao_1(raiz, 50);
    raiz = inserir_versao_1(raiz, 30);
    raiz = inserir_versao_1(raiz, 20);
    raiz = inserir_versao_1(raiz, 40);
    raiz = inserir_versao_1(raiz, 70);
    raiz = inserir_versao_1(raiz, 60);
    raiz = inserir_versao_1(raiz, 80);

    printf("Árvore em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    int chaveBusca = 40;
    NoArv* resultadoBusca = buscar(raiz, chaveBusca);
    if (resultadoBusca != NULL) {
        printf("Elemento %d encontrado na árvore.\n", chaveBusca);
    } else {
        printf("Elemento %d não encontrado na árvore.\n", chaveBusca);
    }

    int chaveRetirar = 30;
    raiz = retirar(raiz, chaveRetirar);
    printf("Árvore após retirar o elemento %d: ", chaveRetirar);
    imprimirEmOrdem(raiz);
    printf("\n");

    // Liberar a memória alocada
    free(raiz);

    return 0;
}
