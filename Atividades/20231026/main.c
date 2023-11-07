#include <stdio.h>
#include "cubo.h"

int main() {
    Cubo* meuCubo = criarCubo(5.0);

    double lado = obterLado(meuCubo);
    double area = calcularArea(meuCubo);
    double volume = calcularVolume(meuCubo);

    printf("Lado do cubo: %.2f\n", lado);
    printf("Área do cubo: %.2f\n", area);
    printf("Volume do cubo: %.2f\n", volume);

    destruirCubo(meuCubo);

    return 0;
}
