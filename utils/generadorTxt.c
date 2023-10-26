#include "generadorTxt.h"
#include "../lib/tipos.h"
#include "string.h"
#include <stdio.h>

void generarArchivoTxtFuente(){

tRegistro registro_1;
FILE * f = fopen("files/alumnos.txt", "wt");

//Genero Registro 1
registro_1.dni = 10000;
strcpy(registro_1.nomyape, "Alan, Genile");
registro_1.macimiento.dia = 13;
registro_1.macimiento.mes = 11;
registro_1.macimiento.anio = 1997;
registro_1.sexo = 'M';
registro_1.ingreso.dia = 10;
registro_1.ingreso.mes = 10;
registro_1.ingreso.anio = 2010;
strcpy(registro_1.carrera, "INF");
registro_1.ma_aprobadas = 10;
registro_1.fe_ultima_arpobada.dia = 0;
registro_1.fe_ultima_arpobada.mes = 0;
registro_1.fe_ultima_arpobada.anio = 0;
registro_1.estado = 'R';
registro_1.baja.dia = 31;
registro_1.baja.mes = 12;
registro_1.baja.anio = 9999;

guardarEnARchivoTxt(f,&registro_1);

//Genero Registro 2
registro_1.fe_ultima_arpobada.dia = 10;
registro_1.fe_ultima_arpobada.mes = 10;
registro_1.fe_ultima_arpobada.anio = 2010;

guardarEnARchivoTxt(f,&registro_1);

//Genero Registro 3

strcpy(registro_1.nomyape, "#2 aLAn $%^gEntIle");

guardarEnARchivoTxt(f,&registro_1);

//Genero Registro 4

strcpy(registro_1.carrera, "AAA");
guardarEnARchivoTxt(f,&registro_1);

//Genero Registro 5
strcpy(registro_1.carrera, "INF");
registro_1.macimiento.dia = 55;
registro_1.macimiento.mes = 105;

guardarEnARchivoTxt(f, &registro_1);

fclose(f);

};

void guardarEnARchivoTxt(FILE * f, const tRegistro * registro){
    fprintf(f, "%ld|%s|%d/%d/%d|%c|%d/%d/%d|%s|%d|%d/%d/%d|%c|%d/%d/%d\n",
            registro->dni,
            registro->nomyape,
            registro->macimiento.dia,
            registro->macimiento.mes,
            registro->macimiento.anio,
            registro->sexo,
            registro->ingreso.dia,
            registro->ingreso.mes,
            registro->ingreso.anio,
            registro->carrera,
            registro->ma_aprobadas,
            registro->fe_ultima_arpobada.dia,
            registro->fe_ultima_arpobada.mes,
            registro->fe_ultima_arpobada.anio,
            registro->estado,
            registro->baja.dia,
            registro->baja.mes,
            registro->baja.anio);
}
