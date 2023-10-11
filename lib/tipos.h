#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

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

#endif // TIPOS_H_INCLUDED
