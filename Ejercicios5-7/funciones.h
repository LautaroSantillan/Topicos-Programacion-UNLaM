#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERROR_FILE 1

#define CANT_PER 5

typedef struct{
    int DNI;
    char apellido[25];
    char nombre[25];
    float sueldo;
}Empleados;

typedef struct{
    int DNI;
    char apellido[25];
    char nombre[25];
    float promedio;
}Estudiantes;

int cargarEmpleados(const char* fileName);
int cargarEstudiantes(const char* fileName);
int mostrarEmpleados(const char* fileName);
int actualizarSueldos(const char* empFileName, const char* estFileName);
int compararEmpleados(const void* a, const void* b);
int compararEstudiantes(const void* a, const void* b);
void ordenarEmpleados(Empleados* empleados, int cantidad);
void ordenarEstudiantes(Estudiantes* estudiantes, int cantidad);
