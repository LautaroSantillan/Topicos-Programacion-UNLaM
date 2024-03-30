#include "funciones.h"

/// La definimos arriba porque no necesariamente el usuario querra usarla
int cantDiasMes(int mes, int anio);
bool esBisiesto(int anio);

Fecha ingresarFecha()
{
    Fecha fecha;

    puts("Ingrese una fecha (D/M/A): ");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    while(!esFechaValida(&fecha))
    {
        puts("Fecha invalida. Ingresela de nuevo (D/M/A): ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    }

    return fecha;
}

bool esFechaValida(const Fecha* f)
{
    if(f->anio < 1601)
        return false;

    if(f->mes < 1 || f->mes > 12)
        return false;

    if(f->dia < 1 || f->dia > cantDiasMes(f->mes, f->anio))
        return false;

    return true;
}

int cantDiasMes(int mes, int anio)
{
    int cdm[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes == 2 && esBisiesto(anio))
        return 29;

    return cdm[mes];
}

bool esBisiesto(int anio)
{
    return anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0);
}

void mostrarFecha(const Fecha* f)
{
    printf("%02d/%02d/%d", f->dia, f->mes, f->anio);
}

/// Funciones propias realizadas

Fecha sumarDiasAFecha(const Fecha* f, int dias)
{
    Fecha nuevaFecha;

    nuevaFecha.dia = f->dia + dias;
    nuevaFecha.mes = f->mes;
    nuevaFecha.anio = f->anio;

    while(nuevaFecha.dia > cantDiasMes(nuevaFecha.mes, nuevaFecha.anio))
    {
        int diasm = cantDiasMes(nuevaFecha.mes,nuevaFecha.anio);

        if(diasm < nuevaFecha.dia && nuevaFecha.mes == 12)
        {
            nuevaFecha.dia -= diasm;
            nuevaFecha.mes = 1;
            nuevaFecha.anio += 1;
        }
        if(diasm < nuevaFecha.dia && nuevaFecha.mes < 12)
        {
            nuevaFecha.dia -= diasm ;
            nuevaFecha.mes += 1;
        }
    }

    return nuevaFecha;
}

//Preguntar

Fecha restarDiasAFecha(const Fecha* f, int dias) {
    Fecha nuevaFecha;

    nuevaFecha.dia = f->dia - dias;
    nuevaFecha.mes = f->mes;
    nuevaFecha.anio = f->anio;

    while (nuevaFecha.dia < 1) {
        nuevaFecha.mes--;
        if (nuevaFecha.mes < 1) {
            nuevaFecha.mes = 12;
            nuevaFecha.anio--;
        }
        nuevaFecha.dia += cantDiasMes(nuevaFecha.mes, nuevaFecha.anio);
    }

    return nuevaFecha;
}

int diaDelAnio(const Fecha* f)
{
    int diaAnio =  f->dia;
    int mesAnio = f->mes;

    for(int i = 1; i < mesAnio ; i++)
    {
        int diam = cantDiasMes(i, f->anio);
        diaAnio += diam;
    }

    return diaAnio;
}

Fecha diaDelAnioAFecha(int diaAnio, int anio)
{
    Fecha fechaAnio;

    fechaAnio.dia = diaAnio;
    fechaAnio.mes = 1;
    fechaAnio.anio = anio;

    while(fechaAnio.dia > cantDiasMes(fechaAnio.mes, anio))
    {
        int diam = cantDiasMes(fechaAnio.mes, anio);
        fechaAnio.dia -= diam;
        fechaAnio.mes += 1;
    }

    return fechaAnio;
}

int diaDeLaSemana(const Fecha* f)
{
    int diaAnio = diaDelAnio(f);
    int diaSem = diaAnio % 7;

    if (diaSem == 0)
        diaSem = 7;

    return diaSem;
}


void determinarDiaSemana(int dia) {
    switch(dia) {
        case 1: printf("El dia de la semana es Lunes\n"); break;
        case 2: printf("El dia de la semana es Martes\n"); break;
        case 3: printf("El dia de la semana es Miercoles\n"); break;
        case 4: printf("El dia de la semana es Jueves\n"); break;
        case 5: printf("El dia de la semana es Viernes\n"); break;
        case 6: printf("El dia de la semana es Sabado\n"); break;
        case 7: printf("El dia de la semana es Domingo\n"); break;
    }
}
