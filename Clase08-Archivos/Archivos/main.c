#include "funcionesArch.h"

///Archivos.exe Empleados.dat

int main(int argc, char* argv[]) ///argc -> cant. de parametros que recibe, argv -> apunta a cada parametro
{
    if(argc != CANT_PARAM)
        return ERR_PARAM;

    int ret = generarArchivoEmpleados(argv[PARAM_NOM_ARCH]);

    if(ret != TODO_OK)
        return ret;

    puts("Antes de actualizar:");
    ret = mostrarArchivoEmpleados(argv[PARAM_NOM_ARCH]);

    if(ret != TODO_OK)
        return ret;

    ret = actualizarSueldosEmpleados(argv[PARAM_NOM_ARCH], atof(argv[PARAM_PORC])); /// atof -> convierte a float

    if(ret != TODO_OK)
        return ret;

    puts("Despues de actualizar:");
    ret = mostrarArchivoEmpleados(argv[PARAM_NOM_ARCH]);

    ret = generarIndiceEmpleados(argv[PARAM_NOM_ARCH], argv[PARAM_NOM_IDX]);

    Vector vecIdx;

    vectorCrear(&vecIdx, sizeof(EmpleadoIdx));

    ret = cargarIndiceEmpleados(&vecIdx, argv[PARAM_NOM_IDX]);

    ret = actualizarSueldo1Empleado(argv[PARAM_NOM_ARCH], &vecIdx, 1, atof(argv[PARAM_PORC]));

    puts("Despues de actualizar 1 empleado:");
    ret = mostrarArchivoEmpleados(argv[PARAM_NOM_ARCH]);

    return ret;
}
