#include <stdio.h>
#include <stdlib.h>

#include "lib/indice.h"
#include "lib/registro.h"
#include "lib/func.h"
#include "lib/fecha.h"


int main()
{
//    tRegistro * registro = malloc(sizeof(tRegistro));
//    registro->dni = 40733281;
//    myStrCopy("ELE", registro->carrera);
//    registro->sexo = 'F';
//    registro->ma_aprobadas = 10;
//    registro->estado = 'R';
//    myStrCopy("2@3aLaN 4123gENtile1523", registro->nomyape);
//
//    char * output = malloc(sizeof(registro->nomyape));
//
//    normalizar(registro->nomyape, output, ',');
//
//    printf("%s", output);
//
//    free(output);
//    free(registro);

    tIndice indice;
    RegIndice registro;
    ind_crear(&indice);

    registro.dni = 43643752;
    registro.nro_reg = 3;

    ind_insertar(&indice, &registro);

    registro.dni = 23643752;
    registro.nro_reg = 2;

    ind_insertar(&indice, &registro);


    registro.dni = 40733281;
    registro.nro_reg = 1;

    ind_insertar(&indice, &registro);


//    RegIndice buscado;
//
//    buscado.dni = 40733281;
//    buscado.nro_reg = 1;
//
//    ind_eliminar(&indice,&buscado);
//
//    for(int i = 0; i < indice.cant; i++){
//        printf("%d %d \n", indice.elementos[i].dni, indice.elementos[i].nro_reg);
//    }

//    RegIndice buscado;
//    buscado.dni = 40733281;
//
//    ind_buscar(&indice,&buscado);
//
//    printf("\nINDEX: %d - %d", buscado.dni, buscado.nro_reg);
//
//
//    ind_vaciar(&indice);

    RegIndice cont;

    ind_primero(&indice, &cont);

    printf("\nINDEX: %d - %d", cont.dni, cont.nro_reg);

    ind_siguiente(&indice, &cont);

    printf("\nINDEX: %d - %d", cont.dni, cont.nro_reg);

    return 0;
}
