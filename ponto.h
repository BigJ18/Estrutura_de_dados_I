#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

struct ponto {

    float x;
    float y;

};

typedef struct ponto Ponto;

Ponto* Cria_Ponto (float x, float y);

void Libera_ponto (Ponto *pto);

int Acessa_ponto (Ponto *pto, float *x, float *y);

int Atribuir_ponto (Ponto *pto, float x, float y);

float Distancia_ponto (Ponto *pto, Ponto *pto2);

#endif
