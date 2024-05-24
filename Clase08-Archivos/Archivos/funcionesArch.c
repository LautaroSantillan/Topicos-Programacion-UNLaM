#include "funcionesArch.h"

bool _ampliarCapVector(Vector* vector);


int generarArchivoEmpleados (const char* nomArchEmpl)
{
    Empleado empleados[CANT_EMPL] =
    {
        {8, "Juan Perez", 240000},
        {5, "Javier Rodriguez", 150000},
        {7, "Arnaldo Aguilar", 130000},
        {2, "Bernardo Bargas", 160000},
        {1, "Carlos Casares", 120000},
        {3, "Dario Dado", 170000},
        {4, "Estefania Estevez", 160000},
        {6, "Fernanda Fernandez", 150000}
    };

    FILE* arch = fopen(nomArchEmpl, "wb");

    if(!arch)
        return ERR_ARCH;

    fwrite(&empleados, sizeof(Empleado), CANT_EMPL, arch); /// estructura, tamaño estructura, cant. registros, puntero al archivo

    fclose(arch);

    return TODO_OK;
}

int mostrarArchivoEmpleados(const char* nomArchEmpl)
{
    FILE* arch = fopen(nomArchEmpl, "rb");

    if(!arch)
        return ERR_ARCH;

    Empleado empl;

    fread(&empl, sizeof(Empleado), 1, arch);

    while(!feof(arch))
    {
        printf("%02d, %-20s, %09.2f\n", empl.legajo, empl.nombre, empl.sueldo);
        fread(&empl, sizeof(Empleado), 1, arch);
    }

    fclose(arch);

    return TODO_OK;
}

int actualizarSueldosEmpleados(const char* nomArchEmpl, float porc)
{
    FILE* arch = fopen(nomArchEmpl, "r+b");

    if(!arch)
        return ERR_ARCH;

    Empleado empl;

    float porcProd = 1 + (float)porc / 100; /// En caso de entero, se castea uno de los dos operandos

    fread(&empl, sizeof(Empleado), 1, arch);

    while(!feof(arch))
    {
        empl.sueldo *= porcProd;
        fseek(arch, -(long)sizeof(Empleado), SEEK_CUR); /// CUR: RELATIVO A DONDE ESTA EL CURSOR, END: FINAL, en caso de warning -> cast a long
        fwrite(&empl, sizeof(Empleado), 1, arch);
        fseek(arch, 0L, SEEK_CUR); /// OBLIGATORIO CUANDO PASAMOS DE ESCRIBIR A LEER O VICEVERSA, NO SE MUEVE EL CURSOR (sobre mismo archivo)
        fread(&empl, sizeof(Empleado), 1, arch);
    }

    putchar('\n');

    fclose(arch);

    return TODO_OK;
}

int generarIndiceEmpleados(const char* nomArchEmpl, const char* nomArchIdx)
{
    EmpleadoIdx emplIdx;

    FILE* arch = fopen(nomArchEmpl, "rb");

    if(!arch)
        return ERR_ARCH;

    FILE* archIdx = fopen(nomArchIdx, "wb");

    if(!archIdx)
    {
        fclose(arch);
        return ERR_ARCH;
    }

    Empleado empl;
    long nroReg = 0;

    fread(&empl, sizeof(Empleado), 1, arch);

    while(!feof(arch))
    {
        emplIdx.legajo = empl.legajo;
        emplIdx.nroReg = nroReg++;
        fwrite(&emplIdx, sizeof(emplIdx), 1, archIdx);
        fread(&empl, sizeof(Empleado), 1, arch);
    }

    putchar('\n');

    fclose(arch);
    fclose(archIdx);

    return TODO_OK;
}

int cargarIndiceEmpleados(Vector* vecIdx, const char* nomArchIdx)
{
    FILE* archIdx = fopen(nomArchIdx, "rb");

    if(!archIdx)
    {
        fclose(arch);
        return ERR_ARCH;
    }

    EmpleadoIdx emplIdx;

    fread(&empl, sizeof(EmpleadoIdx), 1, arch);

    while(!feof(archIdx))
    {
        ret = vectorOrdInsertar(vecIdx, &emplIdx, cmpEmplIdx);

        if(ret != TODO_OK)
        {
            fclose(archIdx);
            return ret;
        }

        fread(&emplIdx, sizeof(EmpleadoIdx), 1, archIdx);
    }

    fclose(archIdx);

    return TODO_OK;
}

int actualizarSueldo1Empleado(const char* nomArchEmpl, Vector* vecIdx, int legajo, float porc)
{
    FILE* archEmp = fopen(nomArchEmpl, "r+b");

    if(!archEmp)
        return ERR_ARCH;

    Empleado empl;

    float porcProd = 1 + (float)porc / 100;

    EmpleadoIdx emplIdx;
    emplIdx.legajo = legajo;

    bool existe = vectorOrdBuscar(vecIdx, &emplIdx, cmpEmplIdx);

    if(!existe)
    {
        fclose(archEmp);
        return ERR_ARCH;
    }

    fseek(archEmp, emplIdx.nroReg * sizeof(Empleado), SEEK_SET);
    fread(&empl, sizeof(Empleado), 1, archEmp);
    emp.sueldo *= porcProd;
    fseek(archEmp, emplIdx.nroReg * sizeof(Empleado), SEEK_SET);
    fwrite(&empl, sizeof(Empleado), 1, archEmp);

    fclose(archEmp);

    return TODO_OK;

}

int cmpEmplIdx(const void* e1, const void* e2)
{
    const EmpleadoIdx* idx1 = e1;
    const EmpleadoIdx* idx2 = e2;

    return idx1->legajo - idx2->legajo;
}

bool vectorCrear(Vector* vec, size_t tamElem)
{
    vec->vec = malloc(CAP_INI * tamElem);

    if(!vec->vec)
        return false; /// No se creo el vector

    vec->ce = 0;
    vec->cap = CAP_INI;
    vec->tamElem = tamElem;

    return true;
}

int vectorOrdInsertar(Vector* vec, int elem)
{
    /// VERIFICAR SI ESTA LLENO EL VECTOR (SI ES ASI, SE INCREMENTA SU MEMORIA)
    if(vec->ce == vec->cap)
    {
        if(!_ampliarCapVector(vec))
            return SIN_MEM;
    }

    /// INSERTAR
    int* posIns = vec->vec;
    int* ultElem = vec->vec + (vec->ce - 1) * vec->tamElem;
    while(posIns <= ultElem && elem > *posIns)
        posIns++;
//    if(posIns <= ultElem && elem == *posIns)
//        return DUPLICADO;
    for(int* i = ultElem; i >= posIns; i--)
        *(i+1) = *i; /// vec[i+1] = vec[i]
    *posIns = elem;
    vec->ce++;

    return TODO_OK;
}

bool _ampliarCapVector(Vector* vector)
{
    size_t nuevaCap = vec->cap * FACTOR_INCR;
    int* nuevoVec = realloc(vec->vec, nuevaCap * sizeof(int));

    if(!nuevoVec)
        return false;

    vec->vec = nuevoVec;
    vec->cap = nuevaCap;

    return true;
}

bool vectorOrdBuscar(const Vector* vector, void* elem, Cmp cmp)
{
    void* posact = vector->vec;
    void* ult = vector->vec + (vector->ce - 1) * vector->tamElem;

    while(posact <= ult && cmp(elem, posact) > 0)
        posact += vector->tamElem;

    if(posact <= ult && cmp(elem, posact) == 0)
    {
        memcpy(elem, posact, vector->tamElem);
        return true;
    }

    return false;
}
