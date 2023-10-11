#include <stdio.h>
#include <stdlib.h>

#include "lib/registro.h"
#include "lib/func.h"
#include "lib/fecha.h"
int main()
{
    tRegistro * registro = malloc(sizeof(tRegistro));
    registro->dni = 40733281;
    myStrCopy("ELE", registro->carrera);
    registro->sexo = 'F';
    registro->ma_aprobadas = 10;
    registro->estado = 'R';

    return 0;
}
