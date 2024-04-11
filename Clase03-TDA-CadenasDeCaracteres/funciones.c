#include "funciones.h"
#include "secuenciaPalabras.h"

char* normalizarCadena(char* cadNormalizada, const char* cadANormalizar)
{
    SecuenciaPalabras secLect, secEscr;
    secuenciaCrear(&secLect, cadANormalizar);
    secuenciaCrear(&secEscr, cadNormalizada);

    Palabra palabra;
    leerPalabra(&secLect, &palabra);
    while(!finSecuencia(&secLect))
    {
        aTitulo(&palabra);
        /// MOSTRAR PALABRA
//        mostrarPalabra(&palabra);
//        putchar('\n');
        /// ESCRIBIR PALABRA
        escribirPalabra(&secEscr, &palabra);
        escribirCaracter(&secEscr, ' ');

        leerPalabra(&secLect, &palabra);
    }

    secuenciaReposicionar(&secEscr, -1);
    secuenciaCerrar(&secEscr);

    return cadNormalizada;
}

bool esLetra(char car)
{
    return (car >= 'A' && car <= 'Z') || (car >= 'a' && car <= 'z');
}

char aMayus(char car)
{
    if(car >= 'a' && car <= 'z')
        return car - 32;
    return car;
}

char aMinus(char car)
{
    if(car >= 'A' && car <= 'Z')
        return car + 32;
    return car;
}
