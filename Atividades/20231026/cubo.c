#include "cubo.h"
#include <stdlib.h>

Cubo* criarCubo(double lado) {
    Cubo* cubo = (Cubo*)malloc(sizeof(Cubo));
    if (cubo) {
        cubo->lado = lado;
    }
    return cubo;
}

double obterLado(Cubo* cubo) {
    return cubo->lado;
}

double calcularArea(Cubo* cubo) {
    return 6 * cubo->lado * cubo->lado;
}

double calcularVolume(Cubo* cubo) {
    return cubo->lado * cubo->lado * cubo->lado;
}

void destruirCubo(Cubo* cubo) {
    free(cubo);
}
