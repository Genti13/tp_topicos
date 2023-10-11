#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "func.h"

#define REGISTRO_VALIDO 1;
#define REGISTRO_INVALIDO 0;

void mostrarRegistro(const tRegistro * registro)
{
    printf("%ld\n", registro->dni);
    printf("%s\n", registro->carrera);
}

int validarDNI(const int dni)
{
    return !(dni >100000000 || dni < 10000);
}

int validarSexo(const char sexo)
{
    return !(sexo != 'F' && sexo != 'M');
}

int validarCarrera(const char * carrera)
{
    const char * codigos[] = {"INF", "ELE", "IND", "ECO", "DER", "ADM", "MED", "EDF", "FIL"};
    const int arrLen = sizeof(codigos)/sizeof(codigos[0]);

    for(int i = 0; i < arrLen; i++)
    {
        if(myStrIquals(carrera, codigos[i]))
        {
            return REGISTRO_VALIDO
        }
    }

    return REGISTRO_INVALIDO;
}

int validarMateriasAprobadas(const int ma)
{
    return ma >= 0;
}

int validarEstado(const char estado)
{
    return !(estado != 'R' && estado != 'B');
}

int validarRegistro(const tRegistro * registro)
{
    if(!validarDNI(registro->dni))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarSexo(registro->sexo))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarCarrera(registro->carrera))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarMateriasAprobadas(registro->ma_aprobadas))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarEstado(registro->estado))
    {
        return REGISTRO_INVALIDO;
    }



    return REGISTRO_VALIDO;
}

