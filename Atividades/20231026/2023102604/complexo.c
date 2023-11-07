#include "complexo.h"
#include <stdlib.h>

Complexo* criarComplexo(double real, double imaginario) {
    Complexo* complexo = (Complexo*)malloc(sizeof(Complexo));
    if (complexo) {
        complexo->real = real;
        complexo->imaginario = imaginario;
    }
    return complexo;
}

void destruirComplexo(Complexo* complexo) {
    free(complexo);
}

Complexo* somarComplexos(Complexo* c1, Complexo* c2) {
    return criarComplexo(c1->real + c2->real, c1->imaginario + c2->imaginario);
}

Complexo* subtrairComplexos(Complexo* c1, Complexo* c2) {
    return criarComplexo(c1->real - c2->real, c1->imaginario - c2->imaginario);
}

Complexo* multiplicarComplexos(Complexo* c1, Complexo* c2) {
    double real = c1->real * c2->real - c1->imaginario * c2->imaginario;
    double imaginario = c1->real * c2->imaginario + c1->imaginario * c2->real;
    return criarComplexo(real, imaginario);
}

Complexo* dividirComplexos(Complexo* c1, Complexo* c2) {
    double divisor = c2->real * c2->real + c2->imaginario * c2->imaginario;
    double real = (c1->real * c2->real + c1->imaginario * c2->imaginario) / divisor;
    double imaginario = (c1->imaginario * c2->real - c1->real * c2->imaginario) / divisor;
    return criarComplexo(real, imaginario);
}
