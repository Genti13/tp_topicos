#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED
#define MAX_DEFAULT_ELEMENTS 100
#define MEM_EXPANSION 30
#define ERROR 0
#define NO 0
#define OK 1

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    unsigned dni;
    unsigned nro_reg;
}RegIndice;

typedef struct{
    RegIndice* elementos;
    int max;
    int cant;
}tIndice;


int ind_crear(tIndice*); //El enunciado dice que sea void, decidi hacerlo int para poner codigo de error
int ind_insertar(tIndice*, const RegIndice*);
int ind_eliminar(tIndice*,RegIndice*);
int ind_buscar(const tIndice*, RegIndice*);
int ind_cargar(tIndice*, const char* path);
int ind_grabar(const tIndice*, const char * path);
void ind_vaciar(tIndice*);
int ind_primero(tIndice*, RegIndice*);
int ind_siguiente(tIndice*, RegIndice*);
int ind_fin(const tIndice*);
void ind_liberar(tIndice*);


#endif // INDICE_H_INCLUDED
