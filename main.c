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

#define FILE_ERROR 1

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
    tFecha proceso;
    tRegistro registro;


    printf("Inserte la fecha actual con el siguiente formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &proceso.dia,&proceso.mes,&proceso.anio);

    while(!validarFecha(&proceso))
    {
        printf("Ingreso una fecha incorrecta, intente denuevo...\n");
        scanf("%d/%d/%d", &proceso.dia,&proceso.mes,&proceso.anio);
    }

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

       if(opcion == '1'){
        printf("ALTA DE REGISTRO: \n");
        altaDeRegistro(&registro, &proceso);
       }else{
       }

        break;
    case '2':
        break;
    case '3':
        break;
    };
    /*

    FALTA:
        Tercera Parte:
            Los metodos que hagan las cosas que pide
    */


//    FILE * archTxt, * archBin;
//
//    if(argc != CANT_ARGS)
//    {
//        printf("Error Argumentos");
//        return FILE_ERROR;
//    }
//
//
//    archTxt = fopen(argv[ARCHIVO_TXT], "r");
//
//    if(!archTxt)
//    {
//        printf("No hay txt");
//        return FILE_ERROR;
//    }
//
//    archBin = fopen(argv[ARCHIVO_ALUMNOS], "wb");
//
//    if(!archBin)
//    {
//        printf("Error creando Bin");
//        return FILE_ERROR;
//    }
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
//
//    tIndice indice;
//    RegIndice registro;
//
//    ind_crear(&indice);
//
//    ind_cargar(&indice, "indices.dat");
//
//    printf("%d - %d", indice.elementos[0].dni, indice.elementos[0].nro_reg);
//    printf("%d - %d", indice.elementos[1].dni, indice.elementos[1].nro_reg);
//
//    ind_vaciar(&indice);
//    ind_liberar(&indice);


    return 0;
}
