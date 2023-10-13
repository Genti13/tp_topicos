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
    myStrCopy("2@3aLaN 4123gENtile1523", registro->nomyape);

    char * output = malloc(sizeof(registro->nomyape));

    normalizar(registro->nomyape, output, ',');

    printf("%s", output);

    free(output);
    free(registro);

    return 0;
}
