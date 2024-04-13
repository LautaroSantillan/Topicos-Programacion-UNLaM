#include "funciones.h"

void vectorCrear(Vector* vec)
{
    vec->ce = 0;
}

void mostrar(Vector *vec)
{
    int *ini = vec->vec;
    int *fin = vec->vec + vec->ce -1;
    while(ini<=fin)
    {
        printf("%d \t",*ini);
        ini++;
    }
}

int vectorInsertarOrd(Vector* vec, int elem)
{
    if(vec->ce == TAM)
        return VEC_LLENO;

    int posIns = 0;
    while(posIns < vec->ce && elem > vec->vec[posIns])
        posIns++;

    if(posIns < vec->ce && elem == vec->vec[posIns])
        return DUPLICADO;

    for(int i=vec->ce-1; i >= posIns; i--)
        vec->vec[i+1] = vec->vec[i];

    vec->vec[posIns] = elem;
    vec->ce++;
    return TODO_OK;
}

int vectorInsertarPrin(Vector* vec, int elem)
{
    if(vec->ce == TAM)
        return VEC_LLENO;

    int posIns = 0;
    for(int i = vec->ce-1; i >= posIns; i--)
        vec->vec[i+1] = vec->vec[i];
    vec->vec[posIns] = elem;
    vec->ce++;
    return TODO_OK;
}

int vectorInsertarFin(Vector* vec, int elem)
{
    if(vec->ce == TAM)
        return VEC_LLENO;

    int posIns = vec->ce;
    vec->vec[posIns] = elem;
    vec->ce++;
    return TODO_OK;
}

int vectorInsertarCualPos(Vector* vec, int pos, int elem)
{
    if(vec->ce == TAM)
        return VEC_LLENO;

    for(int i = vec->ce-1; i >= pos; i--)
        vec->vec[i+1] = vec->vec[i];
    vec->vec[pos] = elem;
    vec->ce++;
    return TODO_OK;
}

int vectorEliminarPos(Vector* vec, int pos)
{
    if(pos > vec->ce-1)
        return ERROR;

    vec->vec[pos] = 0;
    for(int i = pos; i <= vec->ce-1; i++)
        vec->vec[i] = vec->vec[i+1];
    vec->ce--;
    return TODO_OK;
}

int vectorEliminarPri(Vector* vec)
{
    int pos = 0;
    if(pos > vec->ce-1)
        return ERROR;

    vec->vec[pos] = 0;
    for(int i = pos; i <= vec->ce-1; i++)
        vec->vec[i] = vec->vec[i+1];
    vec->ce--;
    return TODO_OK;
}

int vectorEliminarUlt(Vector* vec)
{
    int pos = vec->ce-1;
    if(pos > vec->ce-1)
        return ERROR;

    vec->ce--;
    return TODO_OK;
}

int vectorEliminarValor(Vector* vec, int elem)
{
    int posElim = 0;
    bool eliminado = false;
    for(int i = 0; i < vec->ce; i++)
    {
        if(vec->vec[i] == elem)
        {
            vec->vec[i] = 0;
            posElim = i;
                for(int j = posElim; j <= vec->ce-1; j++)
                    vec->vec[j] = vec->vec[j+1];
            eliminado = true;
            vec->ce--;
        }
    }
    if(eliminado)
        return TODO_OK;
    else
        return ERROR;
}

int vectorEliminarValorOrd(Vector* vec, int elem)
{
    for(int i = 0; vec->vec[i] <= elem; i++)
    {
        if(vec->vec[i] == elem)
        {
            for(int j = i; j < vec->ce; j++)
                vec->vec[j] = vec->vec[j+1];
            vec->ce--;
            return TODO_OK;
        }
    }

    return ERROR;
}

int vectorBuscarElemOrd(Vector* vec, int elem)
{
    for(int i = 0; vec->vec[i] <= elem; i++)
    {
        if(vec->vec[i] == elem)
            return TODO_OK;
    }

    return ERROR;
}

int vectorBuscarElemDes(Vector* vec, int elem)
{
    for(int i = 0; i < vec->ce; i++)
    {
        if(vec->vec[i] == elem)
        {
            for(int j = i; j < vec->ce; j++)
                vec->vec[j] = vec->vec[j+1];
        }
        vec->ce--;
        return TODO_OK;
    }

    return ERROR;
}

int vectorEliminarDupOrd(Vector* vec, int elem)
{
    for(int i = 0; vec->vec[i] <= elem; i++)
    {
        if(vec->vec[i] == elem)
            return TODO_OK;
    }

    return ERROR;
}
