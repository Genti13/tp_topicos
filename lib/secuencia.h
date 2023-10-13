#ifndef SECUENCIA_H_INCLUDED
#define SECUENCIA_H_INCLUDED

#include "tipos.h"

#define FIN_DE_CADENA(c) ((c) == '\0')

void crearSecuencia(secuenciaPalabra *, char *);
int leerPalabra(secuenciaPalabra *, palabra *);
void aTitulo(palabra *);
void escribirPalabra(secuenciaPalabra *, const palabra *);
void normalizar(const char *, char *, const char);
int finSecuencia(const secuenciaPalabra *);
void escribirCaracter(secuenciaPalabra *, char);
void reposicionarCursor(secuenciaPalabra *, const int);

#endif // SECUENCIA_H_INCLUDED
