#include <stdio.h>
#include "lista_ligada.h"

int main() {
    ListaLigada* lista = criarLista();

    // Adicione elementos à lista de teste
    inserirElemento(lista, 1);
    inserirElemento(lista, 2);
    inserirElemento(lista, 3);
    inserirElemento(lista, 4);

    printf("Lista original: ");
    imprimirLista(lista);

    ListaLigada* listaA = permutarA(lista);
    printf("Permutação A: ");
    imprimirLista(listaA);

    ListaLigada* listaB = permutarB(lista);
    printf("Permutação B: ");
    imprimirLista(listaB);

    ListaLigada* listaC = copiarLista(lista);
    printf("Cópia da Lista Original: ");
    imprimirLista(listaC);

    ListaLigada* listaConcatenada = concatenarListas(lista, listaA);
    printf("Lista Concatenada: ");
    imprimirLista(listaConcatenada);

    ListaLigada* listaIntercalada = intercalarListas(lista, listaA);
    printf("Lista Intercalada: ");
    imprimirLista(listaIntercalada);

    // Libere a memória alocada
    // ...

    return 0;
}
