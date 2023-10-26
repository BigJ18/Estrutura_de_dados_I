#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Ponto.h"

struct ponto {
    float x;
    float y;

};

Ponto * Cria_ponto(float x, float y) {
    Ponto *out=malloc(sizeof(Ponto));
    out ->x=x;
    out ->y=y;
    return out;

}

void Libera_ponto (Ponto *pto) {
    free(pto);

}

int Acessa_ponto(Ponto *pto, float *x, float *y) {
    if (pto==NULL)
        return 0;
    *x= pto->x;
    *y= pto->y;
    return 1;

}

int Atribuir_ponto(Ponto *pto, float x, float y) {
    if (pto == NULL)
        return 0;
    pto->x=x;
    pto->y=y;
    return 1;

}

float Distancia_ponto (Ponto *pto1, Ponto *pto2) {
    float dx, dy, dist;
    dx = ptol->x - pto2->x;
    dy = ptol->y - pto2->y;
    dist = sqrt(dx*dy + dy*dy);
    return dist;
}
