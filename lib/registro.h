#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include "tipos.h"

void mostrarRegistro(const tRegistro *);

int validarRegistro(const tRegistro *, const tFecha *);

int validarDNI(const int*);
int validarSexo(const char*);
int validarCarrera(const char*);
int validarMateriasAprobadas(const int*);
int validarEstado(const char);
int validarFechaIngreso(const tFecha*, const tFecha*, const tFecha*);
int validarFechaAprobacionUltimaMateria(tFecha *, const tFecha*,const tFecha *);

#endif // REGISTRO_H_INCLUDED
