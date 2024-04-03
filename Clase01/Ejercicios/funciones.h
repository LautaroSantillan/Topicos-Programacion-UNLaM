#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///TDA: Tipo de Dato Abstracto

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

/// Primitivas

Fecha ingresarFecha();
bool esFechaValida(const Fecha* f);
void mostrarFecha(const Fecha* f);

/// Funciones a realizar

Fecha sumarDiasAFecha(const Fecha* f, int dias); /// Listo
Fecha restarDiasAFecha(const Fecha* f, int dias); /// A revisar
int difEntreFechas(const Fecha* f1, const Fecha* f2);
int diaDelAnio(const Fecha* f); /// Listo
Fecha diaDelAnioAFecha(int diaAnio, int anio); /// Listo
int diaDeLaSemana(const Fecha* f); /// A Revisar
void determinarDiaSemana (int dia); /// Listo
