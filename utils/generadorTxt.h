#ifndef GENERADORTXT_H_INCLUDED
#define GENERADORTXT_H_INCLUDED

#include "../lib/tipos.h"
#include <stdio.h>

//Esta funcion no va arecibir parametros ya que va a estar hardcodeando el
//Archivo que queremos
void generarArchivoTxtFuente();

void guardarEnARchivoTxt(FILE *, const tRegistro *);


#endif // GENERADORTXT_H_INCLUDED
