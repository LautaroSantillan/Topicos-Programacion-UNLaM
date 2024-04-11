#include "funciones.h"

int main()
{
    /// '\0' (caracter nulo) es el fin de una cadena.
    char cadANormalizar[] = "&^&*^@#&*^$ esTA@^#&*@^$*eS unA@^#&*@^$*cAdEnA@^#&*@^$* A nOrMaLiZaR@^#&*@^$*";
    char cadNormalizada[TAM];
    printf("%s\n", normalizarCadena(cadNormalizada, cadANormalizar));

    return 0;
}
