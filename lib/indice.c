#include "indice.h"

int ind_crear(tIndice* indice)
{
    indice->elementos = (RegIndice*)malloc(sizeof(RegIndice) * MAX_DEFAULT_ELEMENTS);

    if(indice->elementos == NULL)
    {
        return ERROR;
    }

    indice->max = 100;
    indice->cant = 0;

    return OK;
};

int ind_insertar(tIndice * indice, const RegIndice * registro)
{

    if(indice->cant >= indice->max)
    {
        RegIndice* r_RegIndice = (RegIndice*)realloc(indice->elementos, MEM_EXPANSION + sizeof(RegIndice));

        if(r_RegIndice == NULL)
        {
            return ERROR;
        }

        indice->elementos = r_RegIndice;
        indice->max += MEM_EXPANSION;
    }

    RegIndice * p_reg = indice->elementos;

    int i = 0;
    while(i < indice->cant && registro->dni > p_reg->dni)
    {
        p_reg++; //Esto termina apuntando a la pos donde insertar el registro
        i++;
    }

    //Busco el ultimo registro y desplazo todo a la derecha
    //Esto apunta a la proxima posicion disponibile
    RegIndice * f_reg = indice->elementos+indice->cant;


    //Retrocedo hasta encontrarme con la posicion donde se va a insertar el nuevo valory freno
    while(f_reg != p_reg)
    {
        *f_reg = *(f_reg-1);

        f_reg--;
    }


    *p_reg=*registro;
    indice->cant++;

    return OK;
}

//Elimina buscando DNI
int ind_eliminar(tIndice * indice, RegIndice* registro)
{
    int encontrado = NO;
    int i = 0;

    RegIndice * p_reg = indice->elementos;

    while(i < indice->cant && !encontrado)
    {

        if(p_reg->dni == registro->dni){
            encontrado=OK;
            break;
        }

        i++;
        p_reg++;
    }

    if(encontrado){
        while(i<indice->cant){
            *p_reg = *(p_reg+1);
            p_reg++;
            i++;
        }
        indice->cant--;
    }

    return encontrado;
}

int ind_buscar(const tIndice * indice, RegIndice * registro){

    int encontrado = NO;
    int i = 0;

    RegIndice * p_reg = indice->elementos;

    while(i < indice->cant && !encontrado)
    {

        if(p_reg->dni == registro->dni){
            encontrado=OK;
            break;
        }

        i++;
        p_reg++;
    }

    if(encontrado){
        *registro = *p_reg;
    }

    return encontrado;
}

void ind_vaciar(tIndice * indice){

        indice->elementos = (RegIndice*)realloc(indice->elementos, MAX_DEFAULT_ELEMENTS + sizeof(RegIndice));
        indice->cant = 0;
        indice->max = 100;

}

void ind_liberar(tIndice*indice){

    free(indice->elementos);

}




int ind_primero(tIndice* indice, RegIndice*registro){

    if(indice->cant <= 0){
        return ERROR;
    }

    *registro = *(indice->elementos);

    return OK;

};


int ind_siguiente(tIndice*indice, RegIndice*registro){

    int encontrado = NO;
    int i = 0;

    RegIndice * p_reg = indice->elementos;

    while(i < indice->cant && !encontrado)
    {

        if(p_reg->dni == registro->dni){
            encontrado=OK;
            break;
        }

        i++;
        p_reg++;
    }

    if(encontrado){
        *registro = *(p_reg+1);
    }

    return encontrado;
};

int ind_fin(const tIndice*indice){
return indice->max == indice->cant};





int ind_cargar(tIndice*indice, const char* path){};
int ind_grabar(const tIndice*indice, const char * path){};
