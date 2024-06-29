#include "funciones.h"

int cargarEmpleados(const char* fileName){
    FILE* pf = fopen(fileName, "wb");
    if(!pf){
        puts("Error al crear el archivo de empleados.\n");
        return ERROR_FILE;
    }

    Empleados emp[CANT_PER] = {
        {45175053, "Santillan", "Lautaro", 2130},
        {46330122, "Perez", "Nazareno", 2300},
        {24013978, "Martinez", "Marcelo", 1540},
        {33458725, "Wilde", "Jordi", 1120},
        {37541245, "Margarito", "Alberto", 1670}
    };
    ordenarEmpleados(emp, CANT_PER);
    fwrite(&emp, sizeof(Empleados), CANT_PER, pf);
    fclose(pf);
    return TODO_OK;
}

int cargarEstudiantes(const char* fileName){
    FILE* pf = fopen(fileName, "wb");
    if(!pf){
        puts("Error al crear el archivo de estudiantes.\n");
        return ERROR_FILE;
    }

    Estudiantes est[CANT_PER] = {
        {37541245, "Margarito", "Alberto", 7},
        {33458725, "Wilde", "Jordi", 7.9},
        {24013978, "Martinez", "Marcelo", 3.3},
        {46330122, "Perez", "Nazareno", 4.5},
        {45175053, "Santillan", "Lautaro", 8.8}
    };
    ordenarEstudiantes(est, CANT_PER);
    fwrite(&est, sizeof(Empleados), CANT_PER, pf);
    fclose(pf);
    return TODO_OK;
}

int mostrarEmpleados(const char* fileName){
    FILE* pf = fopen(fileName, "rb");
    if(!pf){
        puts("Error al abrir el archivo de empleados.\n");
        return ERROR_FILE;
    }

    Empleados emp;
    while(fread(&emp, sizeof(Empleados), 1, pf) == 1) {
        printf("%d %s %s %.2f\n", emp.DNI, emp.apellido, emp.nombre, emp.sueldo);
    }
    fclose(pf);
    return TODO_OK;
}

int actualizarSueldos(const char* empFileName, const char* estFileName){
    Empleados emp[CANT_PER];
    Estudiantes est[CANT_PER];

    FILE* empFile = fopen(empFileName, "r+");
    if (!empFile){
        puts("Error al abrir el archivo de empleados en actualizar.\n");
        return ERROR_FILE;
    }
    FILE* estFile = fopen(estFileName, "rb");
    if (!estFile){
        puts("Error al abrir el archivo de estudiantes en actualizar.\n");
        fclose(empFile);
        return ERROR_FILE;
    }

    fread(emp, sizeof(Empleados), CANT_PER, empFile);
    fread(est, sizeof(Estudiantes), CANT_PER, estFile);

    for (int i = 0; i < CANT_PER; i++) {
        if (est[i].promedio > 7.0) {
            for (int j = 0; j < CANT_PER; j++) {
                if (emp[j].DNI == est[i].DNI) {
                    emp[j].sueldo *= 1.0728;
                    break;
                }
            }
        }
    }

    fseek(empFile, 0, SEEK_SET);
    fwrite(emp, sizeof(Empleados), CANT_PER, empFile);

    fclose(empFile);
    fclose(estFile);
    return TODO_OK;
}

int compararEmpleados(const void* a, const void* b) {
    Empleados* emp1 = (Empleados*)a;
    Empleados* emp2 = (Empleados*)b;

    int cmpApellido = strcmp(emp1->apellido, emp2->apellido);
    if (cmpApellido != 0) {
        return cmpApellido;
    }

    int cmpNombre = strcmp(emp1->nombre, emp2->nombre);
    if (cmpNombre != 0) {
        return cmpNombre;
    }

    return emp1->DNI - emp2->DNI;
}

int compararEstudiantes(const void* a, const void* b) {
    Estudiantes* est1 = (Estudiantes*)a;
    Estudiantes* est2 = (Estudiantes*)b;

    int cmpApellido = strcmp(est1->apellido, est2->apellido);
    if (cmpApellido != 0) {
        return cmpApellido;
    }

    int cmpNombre = strcmp(est1->nombre, est2->nombre);
    if (cmpNombre != 0) {
        return cmpNombre;
    }

    return est1->DNI - est2->DNI;
}

void ordenarEmpleados(Empleados* empleados, int cantidad) {
    qsort(empleados, cantidad, sizeof(Empleados), compararEmpleados);
}

void ordenarEstudiantes(Estudiantes* estudiantes, int cantidad) {
    qsort(estudiantes, cantidad, sizeof(Estudiantes), compararEstudiantes);
}
