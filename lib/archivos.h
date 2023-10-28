#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include "tipos.h"

int obtenerRegistro(tRegistro *, char * buff);
int cargarBinDesdeTxt(FILE * txt, FILE * bin,const tFecha *);
int guardarRegistroEnTxt(FILE *, tRegistro *);

#endif // ARCHIVOS_H_INCLUDED
