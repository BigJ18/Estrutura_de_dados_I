#include "lista.h"
#include <stdio.h>

int main() {
    struct ListaLinearSequencial minhaLista;
    inicializarLista(&minhaLista);

    adicionarElemento(&minhaLista, 10);
    adicionarElemento(&minhaLista, 20);
    adicionarElemento(&minhaLista, 30);

    printf("Elementos na lista: ");
    for (int i = 0; i < minhaLista.tamanho_atual; i++) {
        printf("%d ", minhaLista.lista[i]);
    }

    return 0;
}
