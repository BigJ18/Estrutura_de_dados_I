#include "lista_ligada_estatica.h"

int main() {
    ListaLigadaEstatica lista;

    // Inicializar lista com alguns elementos para teste
    inicializarLista(&lista);
    lista.dados[0] = 1;
    lista.dados[1] = 2;
    lista.dados[2] = 3;
    lista.tamanho = 3;

    printf("Lista Original:\n");
    imprimirLista(&lista);

    // Permutar elementos conforme a opção a)
    permutarElementosA(&lista);
    printf("\nPermutacao a) l2, l3, ..., ln, l1:\n");
    imprimirLista(&lista);

    // Reinicializar lista para o teste b)
    inicializarLista(&lista);
    lista.dados[0] = 1;
    lista.dados[1] = 2;
    lista.dados[2] = 3;
    lista.tamanho = 3;

    // Permutar elementos conforme a opção b)
    permutarElementosB(&lista);
    printf("\nPermutacao b) ln, ln‐1,…, l1:\n");
    imprimirLista(&lista);

    return 0;
}
