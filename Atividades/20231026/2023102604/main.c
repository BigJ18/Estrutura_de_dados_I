#include <stdio.h>
#include "complexo.h"

int main() {
    Complexo* z1 = criarComplexo(3.0, 4.0);  // z1 = 3 + 4i
    Complexo* z2 = criarComplexo(1.0, -2.0); // z2 = 1 - 2i

    Complexo* soma = somarComplexos(z1, z2);
    Complexo* subtracao = subtrairComplexos(z1, z2);
    Complexo* multiplicacao = multiplicarComplexos(z1, z2);
    Complexo* divisao = dividirComplexos(z1, z2);

    printf("Soma: %.2f + %.2fi\n", soma->real, soma->imaginario);
    printf("Subtracao: %.2f + %.2fi\n", subtracao->real, subtracao->imaginario);
    printf("Multiplicacao: %.2f + %.2fi\n", multiplicacao->real, multiplicacao->imaginario);
    printf("Divisao: %.2f + %.2fi\n", divisao->real, divisao->imaginario);

    destruirComplexo(z1);
    destruirComplexo(z2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}
