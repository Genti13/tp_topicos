#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lib/indice.h"
#include "lib/registro.h"
#include "lib/func.h"
#include "lib/fecha.h"
#include "utils/generadorTxt.h"
#include "lib/archivos.h"

#define ARCHIVO_ALUMNOS 2
#define ARCHIVO_TXT 1
#define CANT_ARGS 3

#define ERROR 1

int main(int argc, char* argv[])
{
//    FILE * archAlumnos;
//    char path[255];
//
//    if(argc == CANT_ARGS)
//    {
//        strcpy(path, CARPETA_DESTINO);
//        strcat(path, argv[ARCHIVO_ALUMNOS]);
//        printf(path);
//        archAlumnos = fopen(path, "wb");
//    }
//    else
//    {
//        archAlumnos = fopen(ARCHIVO_DEFAULT, "wb");
//    };
//
//    tRegistro registro;
//    fread(&registro,sizeof(tRegistro),1,archAlumnos);
//
//    while(feof(archAlumnos)){
//        fread(&registro,sizeof(tRegistro),1,archAlumnos);
//    }
//
//
//    fclose(archAlumnos);

    char opcion;
    int dni;
    printf("Seleccionar Opcion:\n");
    printf("1. Alta/Baja\n");
    printf("2. Listad Bajas\n");
    printf("3. Listar Ordenado\n");
    scanf(" %c", &opcion);

    while (opcion < '1' || opcion > '3')
    {
        printf("Ingreso una opcion no valida, intente de nuevo...\n");
        scanf(" %c", &opcion);
    }

    switch(opcion)
    {
    case '1':
        printf("Seleccionar Opcion:\n");
        printf("1. Alta\n");
        printf("2. Baja\n");
        scanf(" %c", &opcion);
        while (opcion < '1' || opcion > '2')
        {
            printf("Ingreso una opcion no valida, intente de nuevo...\n");
            scanf(" %c", &opcion);
        }

        printf("Ingrese DNI:\n");
        scanf("%d", &dni);
        break;
    case '2':
        break;
    case '3':
        break;
    };

/*
FALTA:
    Segunda Parte:
        2. Generar el Indice
    Tercera Parte:
        Los metodos que hagan las cosas que pide
    Cuarta Parte:
        Cargar y Grabar Array desde ARchivo

*/

//    FILE * archTxt, * archBin;
//    tRegistro registro;
//
//    if(argc != CANT_ARGS){
//        printf("Error Argumentos");
//        return ERROR;
//    }
//
//
//    archTxt = fopen(argv[ARCHIVO_TXT], "r");
//
//    if(!archTxt)
//    {
//        printf("No hay txt");
//        return ERROR;
//    }
//
//    archBin = fopen(argv[ARCHIVO_ALUMNOS], "wb");
//
//    if(!archBin){
//        printf("Error creando Bin");
//        return ERROR;
//    }
//
//
//    tFecha proceso;
//    proceso.dia = 25;
//    proceso.mes = 10;
//    proceso.anio = 2023;
//
//    cargarBinDesdeTxt(archTxt, archBin,&proceso);
//
//    fclose(archBin);
//    fclose(archTxt);



    return 0;
}
