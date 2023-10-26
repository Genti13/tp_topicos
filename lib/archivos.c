#include "archivos.h"
#include "registro.h"

int obtenerRegistro(tRegistro * registro, char * buff)
{
    sscanf(buff, "%lu|%39[^|]|%d/%d/%d|%c|%d/%d/%d|%3s|%u|%d/%d/%d|%c|%d/%d/%d\n",
           &registro->dni, registro->nomyape,
           &registro->macimiento.dia, &registro->macimiento.mes, &registro->macimiento.anio,
           &registro->sexo,
           &registro->ingreso.dia, &registro->ingreso.mes, &registro->ingreso.anio,
           registro->carrera, &registro->ma_aprobadas,
           &registro->fe_ultima_arpobada.dia, &registro->fe_ultima_arpobada.mes, &registro->fe_ultima_arpobada.anio,
           &registro->estado,
           &registro->baja.dia, &registro->baja.mes, &registro->baja.anio);

    return 1;
}

int cargarBinDesdeTxt(FILE * txt, FILE * bin, const tFecha * proceso)
{

    char buff[255];
    tRegistro registro;
    FILE * errorTxt = NULL;

    while(fgets(buff, sizeof(buff),txt))
    {
        obtenerRegistro(&registro, buff);

        if(validarRegistro(&registro, proceso))
        {
            fwrite(&registro, sizeof(tRegistro),1,bin);
        }
        else
        {

            if(!errorTxt)
            {
                errorTxt= fopen("error.txt", "wt");
            }

            guardarRegistroEnTxt(errorTxt, &registro);
        }
    }


    if(errorTxt)
    {
        fclose(errorTxt);

    }

    return 1;



}

int guardarRegistroEnTxt(FILE * file, tRegistro * registro)
{
    fprintf(file, "%ld|%s|%d/%d/%d|%c|%d/%d/%d|%s|%d|%d/%d/%d|%c|%d/%d/%d\n",
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

            return 1;
};
