#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include "tipos.h"

void mostrarRegistro(const tRegistro *);

int validarRegistro(const tRegistro *);

int validarDNI(const int);
int validarSexo(const char);
int validarCarrera(const char*);
int validarMateriasAprobadas(const int);
int validarEstado(const char);

#endif // REGISTRO_H_INCLUDED
