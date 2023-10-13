#include "secuencia.h"
#include "func.h"

#define TODO_OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//Inicializo la estructura con una cadena
void crearSecuencia(secuenciaPalabra * secu, char* cad)
{
    secu->cad = cad;
    secu->cur = cad;
    secu->fin = FALSE;
}

int leerPalabra(secuenciaPalabra * secu, palabra * palabra)
{
    char * curPal = palabra->val;

    while(*secu->cur && !is_alpha(*secu->cur))
    {
        secu->cur++;
    }

    if(!*secu->cur)
    {
        secu->fin = TRUE;
        return ERROR;
    }

    while(*secu->cur && is_alpha(*secu->cur))
    {
        *curPal=*secu->cur;
        curPal++;
        secu->cur++;
    }

    *curPal='\0';
    return TODO_OK;
}

void escribirPalabra(secuenciaPalabra * secu, const palabra * palabra)
{
    char * curPal = palabra->val;

    while(*curPal)
    {
        *secu->cad = *curPal;
        secu->cad++;
        curPal++;
    }
}

void aTitulo(palabra * palabra)
{
    char * curPal = palabra->val;

    *curPal = myUpper(*curPal);
    curPal++;
    while(*curPal)
    {
        *curPal = myLower(*curPal);
        curPal++;
    }
}

int finSecuencia(const secuenciaPalabra * secuencia)
{
    return secuencia->fin;
}

escribirCaracter(secuenciaPalabra * secuencia, char car)
{
    *secuencia->cad = car;
    secuencia->cad++;
}

void reposicionarCursor(secuenciaPalabra * secu, const int pos)
{
    secu->cad+=pos;
}

void normalizar(const char * texto, char * normalizado, const char separador)
{
    secuenciaPalabra secL, secE;
    palabra pal;

    crearSecuencia(&secL, (char*)texto);
    crearSecuencia(&secE, normalizado);

    leerPalabra(&secL, &pal);

    while(!finSecuencia(&secL))
    {
        aTitulo(&pal);
        escribirPalabra(&secE, &pal);
        escribirCaracter(&secE, separador);

        leerPalabra(&secL, &pal);
    }

    reposicionarCursor(&secE, -1);

    escribirCaracter(&secE, '\0');
}
