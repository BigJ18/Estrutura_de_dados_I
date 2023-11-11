#include "lista.h"
#include <stdio.h>

int main() {
    LISTA minhaLista = criarLista(5);

    inserirElemento(&minhaLista, 3);
    inserirElemento(&minhaLista, 1);
    inserirElemento(&minhaLista, 4);
    inserirElemento(&minhaLista, 2);
    inserirElemento(&minhaLista, 6);

    printf("Lista original:\n");
    imprimirListaIterativo(minhaLista);

    printf("Lista ordenada:\n");
    for (int i = 1; i <= 5; i++) {
        inserirElementoOrdenado(&minhaLista, i);
    }
    imprimirListaIterativo(minhaLista);

    printf("Busca binária - Índice do elemento 3: %d\n", buscaBinariaRecursiva(minhaLista, 3, 0, minhaLista.quantidade - 1));

    printf("Imprimir Lista Recursivo:\n");
    imprimirListaRecursivo(minhaLista, 0);

    printf("Maior elemento: %d\n", buscarMaiorRecursivo(minhaLista, minhaLista.quantidade - 1));
    printf("Menor elemento: %d\n", buscarMenorRecursivo(minhaLista, minhaLista.quantidade - 1));
    printf("Soma dos elementos: %d\n", somaElementosRecursivo(minhaLista, minhaLista.quantidade - 1));
    printf("Produto dos elementos: %d\n", produtoElementosRecursivo(minhaLista, minhaLista.quantidade - 1));
    printf("Olá mundo");

    liberarLista(&minhaLista);

    return 0;
}
