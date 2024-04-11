#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define TAM_PAL 101

typedef struct{
    char* cursor;
    bool finSec;
}SecuenciaPalabras;

typedef struct{
    char vec[TAM_PAL];
}Palabra;

void secuenciaCrear(SecuenciaPalabras* sec, const char* cad);
bool leerPalabra(SecuenciaPalabras* sec, Palabra* pal);
void escribirPalabra(SecuenciaPalabras* sec, const Palabra* pal);
void escribirCaracter(SecuenciaPalabras* sec, char c);
bool finSecuencia(const SecuenciaPalabras* sec);
void mostrarPalabra(const Palabra* pal);
void aTitulo(Palabra* pal);
void secuenciaReposicionar(SecuenciaPalabras* sec, int);
void secuenciaCerrar(SecuenciaPalabras* sec);
