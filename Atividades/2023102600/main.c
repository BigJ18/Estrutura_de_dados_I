#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ponto.h"

int main()
{
   Ponto *m_pto;
   float ext_x, ext_y;

m_pto=Cria_ponto(2.0, 2.1);

Acessa_ponto(m_pto, &ext_x, &ext_y);

printf("n\Valor de x= %f", m_pto->x);
printf("n\Valor de y= %f", m_pto->y);

Acessa_ponto(m_pto, &ext_x, &ext_y);

Atribuir_ponto(m_pto,5.0, 5.3);

Acessa_ponto(m_pto,&ext_x,&ext_y);

printf("n\valor de x= %f", m_pto->x);
printf("n\valor de y= %f", m_pto->y);

Libera_ponto(m_pto);

printf("Hello world\n");
return 0;

}
