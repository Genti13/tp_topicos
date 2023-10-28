#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "func.h"

#define REGISTRO_VALIDO 1;
#define REGISTRO_INVALIDO 0;

#define FECHA_BAJA_DEFAULT_DIA 31;
#define FECHA_BAJA_DEFAULT_MES 12;
#define FECHA_BAJA_DEFAULT_ANIO 9999;

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
        printf("DNI Invalido\n");
        return REGISTRO_INVALIDO;
    }

    if(!validarFecha(&registro->macimiento))
    {
        printf("Fecha de Nacimiento Invalido\n");
        return REGISTRO_INVALIDO;
    }

    if(!validarSexo(&registro->sexo))
    {
        printf("Sexo Invalido\n");
        return REGISTRO_INVALIDO;
    }

    if(!validarFechaIngreso(&registro->macimiento, &registro->ingreso, proceso))
    {
        printf("Fecha de Ingreso Invalido\n");
        return REGISTRO_INVALIDO;
    }

    if(!validarCarrera(registro->carrera))
    {
        printf("CArrera Invalido\n");
        return REGISTRO_INVALIDO;
    }

    if(!validarMateriasAprobadas(&registro->ma_aprobadas))
    {
        printf("Materias Aprobadas Invalido\n");
        return REGISTRO_INVALIDO;
    }

    if(!validarFechaAprobacionUltimaMateria(&registro->fe_ultima_arpobada,
                                            &registro->ingreso, proceso))
    {
        printf("Fecha Ultima Aprobacion Invalido\n");
        return REGISTRO_INVALIDO;
    };

    if(!validarEstado(&registro->estado))
    {
        printf("Estado Invalido\n");
        return REGISTRO_INVALIDO;
    }

    char nomyape[40];
    normalizar(&registro->nomyape, &nomyape, ",");
    myStrCopy(nomyape, registro->nomyape);

    return REGISTRO_VALIDO;
}

int altaDeRegistro(tRegistro * registro, const tFecha * proceso)
{
    printf("Ingrese los siguientes datos:");

    printf("\nDNI: ");
    fflush(stdout);
    scanf("%lu", &registro->dni);

    printf("Nombre y Apellido: ");
    fflush(stdout);
    scanf(" %[^'\n']", registro->nomyape);

    printf("Fecha de Nacimiento: ");
    fflush(stdout);
    scanf("%d/%d/%d", &registro->macimiento.dia, &registro->macimiento.mes, &registro->macimiento.anio);

    printf("Sexo: ");
    fflush(stdout);
    scanf(" %c", &registro->sexo);

    printf("Fecha de Ingreso: ");
    fflush(stdout);
    scanf("%d/%d/%d", &registro->ingreso.dia, &registro->ingreso.mes, &registro->ingreso.anio);

    printf("Carrera: ");
    fflush(stdout);
    scanf(" %[^'\n']", registro->carrera);

    printf("Materias Aprobadas: ");
    fflush(stdout);
    scanf("%d", &registro->ma_aprobadas);

    printf("Fecha de Aprobacion Ultima Materia, utilice 0 si no aplica: ");
    fflush(stdout);
    scanf("%d/%d/%d", &registro->fe_ultima_arpobada.dia, &registro->fe_ultima_arpobada.mes, &registro->fe_ultima_arpobada.anio);

    if(registro->fe_ultima_arpobada.dia == 0 || !validarFecha(&registro->fe_ultima_arpobada))
    {
        registro->fe_ultima_arpobada.dia = registro->ingreso.dia;
        registro->fe_ultima_arpobada.mes = registro->ingreso.mes;
        registro->fe_ultima_arpobada.anio = registro->ingreso.anio;
    }

    registro->estado = 'R';
    registro->baja.dia = FECHA_BAJA_DEFAULT_DIA;
    registro->baja.mes = FECHA_BAJA_DEFAULT_MES;
    registro->baja.anio = FECHA_BAJA_DEFAULT_ANIO;

    if(!validarRegistro(registro, proceso)){
        printf("Los datos Ingresados Son INVALIDOS");
        return REGISTRO_INVALIDO;
    }




    return REGISTRO_VALIDO;
}
