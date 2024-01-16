#include <stdio.h>
#include "hangar.h"

int main() {
    Hangar hangar;
    inicializarHangar(&hangar, 10);

    Aviao aviao1 = {"Boeing 747", 1};
    Aviao aviao2 = {"Airbus A380", 2};
    Aviao aviao3 = {"Cessna 172", 3};

    adicionarAviao(&hangar, aviao1);
    adicionarAviao(&hangar, aviao2);
    adicionarAviao(&hangar, aviao3);

    printf("Número de aviões no hangar: %d\n", contarAvioes(&hangar));

    listarAvioes(&hangar);
    listarPrimeiroAviao(&hangar);

    removerAviao(&hangar);
    listarAvioes(&hangar);

    removerAviaoPorPosicao(&hangar, 1);
   
