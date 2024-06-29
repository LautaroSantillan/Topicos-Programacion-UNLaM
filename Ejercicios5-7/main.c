#include "funciones.h"

///Ejercicio 5.7
/*Se dispone de dos archivos binarios: <empleados> y <estudiantes>.
Cada registro del primer archivo contiene los campos:
- <dni>, <apellido>, <nombre> y <sueldo>
en tanto que los del segundo:
- <dni>, <apellido>, <nombre> y <promedio>.
Ambos archivos están ordenados alfabéticamente por <apellido> / <nombre> / <dni>.
Ambos archivos deben ser leídos sólo una vez, y no deben ser almacenados en arrays. El sueldo es
double y el promedio es float.
Escriba un programa que, leyendo ambos archivos, actualice el sueldo de aquellos empleados que
tengan un registro de estudiante con un promedio superior a 7, en un 7,28%.*/

/// empleados.dat estudiantes.dat
int main(int argc, char* argv[])
{
    cargarEmpleados(argv[1]);
    cargarEstudiantes(argv[2]);
    puts("\nEmpleados después de actualizar sueldos:\n");
    actualizarSueldos(argv[1], argv[2]);
    mostrarEmpleados(argv[1]);
    return TODO_OK;
}
