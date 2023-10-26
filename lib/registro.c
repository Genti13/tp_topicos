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

int validarDNI(const long unsigned int* dni)
{
return !(*dni >100000000 || *dni < 10000);
}

int validarSexo(const char *sexo)
{
    return !(*sexo != 'F' && *sexo != 'M');
}

int validarCarrera(const char *carrera)
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

int validarMateriasAprobadas(const unsigned int *ma)
{
    return ma >= 0;
}

int validarEstado(const char *estado)
{
    return !(*estado != 'R' && *estado != 'B');
}


int validarFechaIngreso(const tFecha * nacimiento, const tFecha *ingreso,
                        const tFecha * proceso)
{
    tFecha nacimientoOffset;
    nacimientoOffset.dia = nacimiento->dia;
    nacimientoOffset.mes = nacimiento->mes;
    nacimientoOffset.anio = nacimiento->anio + 10;

    if(compararFecha(proceso, ingreso) != -1 &&
            compararFecha(ingreso, nacimientoOffset) == 1 &&
            validarFecha(ingreso))
    {
        return REGISTRO_VALIDO;
    }
    else
    {
        return REGISTRO_INVALIDO;
    }
};

int validarFechaAprobacionUltimaMateria(tFecha * ultimaAprobada,
                                        const tFecha *ingreso,
                                        const tFecha * proceso)
{

    if(fechaVacia(ultimaAprobada))
    {
        ultimaAprobada->dia = ingreso->dia;
        ultimaAprobada->mes = ingreso->mes;
        ultimaAprobada->anio = ingreso->anio;
    }

    if(compararFecha(ultimaAprobada, ingreso) != -1 &&
            compararFecha(ultimaAprobada, proceso) != 1)
    {
        return REGISTRO_VALIDO;
    }
    else
    {
        return REGISTRO_INVALIDO;
    }

};

int validarRegistro(tRegistro * registro, const tFecha * proceso)
{
    if(!validarDNI(&registro->dni))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarFecha(&registro->macimiento))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarSexo(&registro->sexo))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarFechaIngreso(&registro->macimiento, &registro->ingreso, proceso))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarCarrera(registro->carrera))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarMateriasAprobadas(&registro->ma_aprobadas))
    {
        return REGISTRO_INVALIDO;
    }

    if(!validarFechaAprobacionUltimaMateria(&registro->fe_ultima_arpobada,
                                            &registro->ingreso, proceso))
    {
        return REGISTRO_INVALIDO;
    };

    if(!validarEstado(&registro->estado))
    {
        return REGISTRO_INVALIDO;
    }

    char nomyape[40];
    normalizar(&registro->nomyape, &nomyape, ",");
    myStrCopy(nomyape, registro->nomyape);

    return REGISTRO_VALIDO;
}

