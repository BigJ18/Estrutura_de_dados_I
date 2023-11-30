#include "lista_ligada_estatica.h"

int main() {
    ListaLigadaEstatica lista1;
    ListaLigadaEstatica lista2;
    ListaLigadaEstatica resultado;

    // Inicializar lista1 com alguns elementos para teste
    inicializarLista(&lista1);
    lista1.dados[0] = 1;
    lista1.dados[1] = 2;
    lista1.dados[2] = 3;
    lista1.tamanho = 3;

    printf("Lista Original 1:\n");
    imprimirLista(&lista1);

    // Copiar lista1 para lista2
    copiarLista(&lista1, &lista2);
    printf("\nLista Copiada 2:\n");
    imprimirLista(&lista2);

    // Concatenar lista1 e lista2
    concatenarListas(&lista1, &lista2, &resultado);
    printf("\nLista Concatenada:\n");
    imprimirLista(&resultado);

    // Inicializar listas para o teste de intercalação
    inicializarLista(&lista1);
    inicializarLista(&lista2);

    lista1.dados[0] = 1;
    lista1.dados[1] = 3;
    lista1.dados[2] = 5;
    lista1.tamanho = 3;

    lista2.dados[0] = 2;
    lista2.dados[1] = 4;
    lista2.dados[2] = 6;
    lista2.tamanho = 3;

    // Intercalar lista1 e lista2
    intercalarListas(&lista1, &lista2, &resultado);
    printf("\nLista Intercalada:\n");
    imprimirLista(&resultado);

    return 0;
}
