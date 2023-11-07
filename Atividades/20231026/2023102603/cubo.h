#ifndef CUBO_H
#define CUBO_H

typedef struct Cubo {
    double lado;
} Cubo;

Cubo* criarCubo(double lado);
double obterLado(Cubo* cubo);
double calcularArea(Cubo* cubo);
double calcularVolume(Cubo* cubo);
void destruirCubo(Cubo* cubo);

#endif
