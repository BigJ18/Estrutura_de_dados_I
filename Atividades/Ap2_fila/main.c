// main.c

#include "fila.h"
#include <stdio.h>

int main() {
    Fila* minhaFila = criarFila();

    enfileirar(minhaFila, 10);
    enfileirar(minhaFila, 20);
    enfileirar(minhaFila, 30);

    printf("Frente da fila: %d\n", frente(minhaFila));

    printf("Desenfileirando: %d\n", desenfileirar(minhaFila));
    printf("Frente da fila após desenfileirar: %d\n", frente(minhaFila));

    esvaziarFila(minhaFila);
    destruirFila(minhaFila);

    return 0;
}
