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

void vectorMostrar(MiVector *vec)
{
    int *ini = vec->vec;
    int *fin = vec->vec + vec->ce -1;
    while(ini<=fin)
    {
        printf("%d \t",*ini);
        ini++;
    }
}

int vectorInsertarFin(MiVector* vec, int elem)
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
    int* ultElem = vec->vec + vec->ce - 1;
    int* posIns = ultElem + 1;
    if(elem == *ultElem)
        return DUPLICADO;
    *posIns = elem;
    vec->ce++;

    return TODO_OK;
}

void intercambiar(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int* buscarMenor(int* inicial, int* fin)
{
    int* m = inicial;
    for(int* i = inicial + 1; i <= fin; i++)
    {
        if(*i < *m)
            m = i;
    }
    return m;
}

void vectorOrdenarBurbujeo(MiVector* vec)
{
    int* ult = vec->vec + vec->ce - 1;
    for(int i = 1, *limJ = ult - 1; i < vec->ce; i++, limJ--)
    {
        for(int* j = vec->vec; j <= limJ; j++)
        {
            if(*j > *(j+1))
                intercambiar(j, j+1);
        }
    }
}

void vectorOrdenarSeleccion(MiVector* vec)
{
    int* ult = vec->vec + vec->ce - 1;
    int* menor;
    for(int* i = vec->vec; i < ult; i++)
    {
        menor = buscarMenor(i, ult);
        intercambiar(menor, i);
    }
}

void vectorOrdenarInsercion(MiVector* vec)
{
    int* ult = vec->vec + vec->ce - 1;
    int* j;
    int elemAIns;
    for(int* i = vec->vec + 1; i <= ult; i++)
    {
        elemAIns = *i;
        j = i - 1;
        while(j >= vec->vec && elemAIns < *j)
            *(j+1) = *j;
        *(j+1) = elemAIns;
    }
}

void vectorInicializarRandom(MiVector* vec, int ce)
{
    vec->ce = ce;
    vec->cap = ce;
    vec->vec = realloc(vec->vec, ce * sizeof(int));
    srand(time(NULL));
    int* ult = vec->vec + vec->ce - 1;
    for(int* i = vec->vec; i <= ult; i++)
        *i = rand();
}
