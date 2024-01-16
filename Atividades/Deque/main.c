#include <stdio.h>
#include "soldado.h"

int main() {
    Deque *deque = criarDeque();

    // Criando 10 soldados para teste
    Soldado soldados[10] = {
        {1, "Soldado 1", 2},
        {2, "Soldado 2", 3},
        {3, "Soldado 3", 1},
        {4, "Soldado 4", 4},
        {5, "Soldado 5", 2},
        {6, "Soldado 6", 3},
        {7, "Soldado 7", 1},
        {8, "Soldado 8", 4},
        {9, "Soldado 9", 2},
        {10, "Soldado 10", 3}
    };

    // Testando as operações no deque
    for (int i = 0; i < 10; i++) {
        inserirInicio(deque, soldados[i]);
    }

    printf("Número de soldados no deque: %d\n", contar(deque));

    printf("Soldados no deque:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d: Código %d, Nome %s, Grau %d\n", i, removerPos(deque, 1).codigo,
               removerPos(deque, 1).nome, removerPos(deque, 1).grau);
    }

    destruirDeque(deque);

    return 0;
}
