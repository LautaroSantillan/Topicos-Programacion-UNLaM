#include "secuenciaPalabras.h"
#include "funciones.h"

void secuenciaCrear(SecuenciaPalabras* sec, const char* cad)
{
    sec->cursor = (char*)cad;
    sec->finSec = false;
}

bool leerPalabra(SecuenciaPalabras* sec, Palabra* pal)
{
    while (*(sec->cursor) != '\0' && !esLetra(*(sec->cursor)))
        sec->cursor++;

    if (*(sec->cursor) == '\0')
    {
        sec->finSec = true;
        return false;
    }

    char* actPal = pal->vec;
    while (*(sec->cursor)!= '\0' && esLetra(*(sec->cursor)))
    {
        *actPal = *(sec->cursor);
        actPal++;
        sec->cursor++;
    }

    *actPal = '\0';

    return true;
}

void escribirPalabra(SecuenciaPalabras* sec, const Palabra* pal)
{
    const char* actPal = pal->vec;
    while(*actPal)
    {
        *sec->cursor = *actPal;
        sec->cursor++;
        actPal++;
    }
}

void escribirCaracter(SecuenciaPalabras* sec, char c)
{
    *sec->cursor = c;
    sec->cursor++;
}

bool finSecuencia(const SecuenciaPalabras* sec)
{
    return sec->finSec;
}

void mostrarPalabra(const Palabra* pal)
{
    const char* i = pal->vec;
    while(*i != '\0')
    {
        putchar(*i);
        i++;
    }
}

void aTitulo(Palabra* pal)
{
    char* actPal = pal->vec;
    *actPal = aMayus(*actPal); /// toupper()
    actPal++;
    while(*actPal) // Es lo mismo que hace => *actPal != '\0'
    {
        *actPal = aMinus(*actPal); /// tolower()
        actPal++;
    }
}

void secuenciaReposicionar(SecuenciaPalabras* sec, int despl)
{
    sec->cursor += despl;
}

void secuenciaCerrar(SecuenciaPalabras* sec)
{
    *sec->cursor = '\0';
}
