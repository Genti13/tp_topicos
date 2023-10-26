#include "fecha.h"

#define VALIDO 1
#define INVALIDO 0
#define ES_BISIESTO(a) ((a)%4 == 0 && ( (a)%100 != 0 || (a)%400==0))

#define IGUAL 0
#define MAYOR 1
#define MENOR -1

int validarFecha(const tFecha * fecha)
{
    const int dias[2][12] =
    {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    return fecha->mes <= 12 && dias[ES_BISIESTO(fecha->anio)][fecha->mes-1] >= fecha->dia && fecha->dia > 0;
}

int compararFecha(const tFecha * fecha1, const tFecha * fecha2){
    int fechaNumero1 = fechaNumero(fecha1);
    int fechaNumero2 = fechaNumero(fecha2);

    if(fechaNumero1 > fechaNumero2){
        return MAYOR;
    }

    if(fechaNumero1 < fechaNumero2){
        return MENOR;
    }

    return IGUAL;
}

int fechaNumero(const tFecha * fecha){
return fecha->anio*10000+fecha->mes*100+fecha->dia;
}

int fechaVacia(const tFecha * fecha){
    return fecha->dia == 0 && fecha->mes == 0 && fecha->anio ==0;
}
