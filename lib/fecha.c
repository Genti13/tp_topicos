#include "fecha.h"

#define VALIDO 1
#define INVALIDO 0
#define ES_BISIESTO(a) ((a)%4 == 0 && ( (a)%100 != 0 || (a)%400==0))

int validarFecha(const tFecha * fecha)
{
    const int dias[2][12] =
    {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    return dias[ES_BISIESTO(fecha->anio)][fecha->mes-1] >= fecha->dia && fecha->dia > 0;
}
