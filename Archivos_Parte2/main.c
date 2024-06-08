#include "funcionesArch.h"

// ConversorBinTxt Empleados.dat B Empleados.txt // V -> V = variable, F = fijo // B = BinATxT  T = TxtABin

int main(int argc, char* argv[])
{
    if(argc - 1 != CANT_ARG)
        return ERR_ARG;

    int ret;

    char tipoArchEnt = *argv[ARG_TIPO_ARCH_ENT]; // argv[ARG_TIPO_ARCH_ENT][0]
    char tipoArchSal = *argv[ARG_TIPO_ARCH_SAL];

    switch(tipoArchEnt)
    {
        case 'B':
            ret = convertirBinATxt(argv[ARG_ARCH_ENT], argv[ARG_ARCH_SAL], sizeof(Empleado), tipoArchSal == 'V' ? empleadoBinATxtV : empleadoBinATxtF);
            break;

        case 'V':
        case 'F':
            ret = convertirTxTABin(argv[ARG_ARCH_ENT], argv[ARG_ARCH_SAL], sizeof(Empleado), tipoArchEnt == 'V' ? empleadoTxtVABin : empleadoTxtFABin);
            mostrarArchivoEmpleados(argv[ARG_ARCH_SAL]);
            break;

    }

    return 0;
}
