#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include "tipos.h"

void mostrarRegistro(const tRegistro *);

int validarRegistro( tRegistro *, const tFecha *);

int validarDNI(const long unsigned int*);
int validarSexo(const char*);
int validarCarrera(const char*);
int validarMateriasAprobadas(const unsigned int*);
int validarEstado(const char*);
int validarFechaIngreso(const tFecha*, const tFecha*, const tFecha*);
int validarFechaAprobacionUltimaMateria(tFecha *, const tFecha*,const tFecha *);
int altaDeRegistro(tRegistro *, const tFecha *);

#endif // REGISTRO_H_INCLUDED
