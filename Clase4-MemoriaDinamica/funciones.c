#include "funciones.h"

bool vectorCrear(MiVector* vec)
{
    vec->vec = malloc(10*sizeof(int)); /// (int*)malloc(10*sizeof(int))
    if(!vec->vec)
        return false; /// No se creo el vector

    vec->ce = 0;
    vec->cap = 10;

    return true;
}

void mostrar(MiVector *vec)
{
    int *ini = vec->vec;
    int *fin = vec->vec + vec->ce -1;
    while(ini<=fin)
    {
        printf("%d \t",*ini);
        ini++;
    }
}

int vectorOrdInsertar(MiVector* vec, int elem)
{
    /// VERIFICAR SI ESTA LLENO EL VECTOR (SI ES ASI, SE INCREMENTA SU MEMORIA)
    if(vec->ce == vec->cap)
    {
        int nuevaCap = vec->cap * 1.5;
        int* nuevoVec = realloc(vec->vec, nuevaCap*sizeof(int));

        if(!nuevoVec)
            return SIN_MEM;
        vec->vec = nuevoVec;
        vec->cap = nuevaCap;
    }
    /// INSERTAR
    int* posIns = vec->vec;
    int* ultElem = vec->vec + vec->ce - 1;
    while(posIns <= ultElem && elem > *posIns)
        posIns++;
    if(posIns <= ultElem && elem == *posIns)
        return DUPLICADO;
    for(int* i = ultElem; i >= posIns; i--)
        *(i+1) = *i; /// vec[i+1] = vec[i]
    *posIns = elem;
    vec->ce++;

    return TODO_OK;
}

int vectorOrdEliminarElem(MiVector* vec, int elem)
{
    int* posElim = vec->vec;
    int* ultElem = vec->vec + vec->ce - 1;

    while(posElim <= ultElem && elem > *posElim)
        posElim++;
    if(posElim > ultElem || elem != *posElim)
        return ERROR;
    for(int* i = posElim; i < ultElem; i++)
        *i = *(i+1);
    vec->ce--;
    if(vec->cap >= vec->ce * 4)
    {
        vec->cap /= 2;
        vec->vec = realloc(vec->vec, vec->cap*sizeof(int));
    }

    return TODO_OK;
}
