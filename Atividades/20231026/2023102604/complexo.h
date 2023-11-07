#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct Complexo {
    double real;
    double imaginario;
} Complexo;

Complexo* criarComplexo(double real, double imaginario);
void destruirComplexo(Complexo* complexo);
Complexo* somarComplexos(Complexo* c1, Complexo* c2);
Complexo* subtrairComplexos(Complexo* c1, Complexo* c2);
Complexo* multiplicarComplexos(Complexo* c1, Complexo* c2);
Complexo* dividirComplexos(Complexo* c1, Complexo* c2);

#endif
