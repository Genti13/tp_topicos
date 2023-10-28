#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

#define TAM_PALABRA 20

typedef struct
{
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;
} tFecha;

typedef struct
{
    unsigned long int dni;
    char nomyape[40];
    tFecha macimiento;
    char sexo;
    tFecha ingreso;
    char carrera[4];
    unsigned int ma_aprobadas;
    tFecha fe_ultima_arpobada;
    char estado;
    tFecha baja;

} tRegistro;

typedef struct{
    char val[TAM_PALABRA];
}palabra;

typedef struct{
    char* cad;
    char* cur;
    int fin;
}secuenciaPalabra;


#endif // TIPOS_H_INCLUDED
