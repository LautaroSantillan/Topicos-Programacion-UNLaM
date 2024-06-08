#include "funcionesArch.h"

int generarArchivoEmpleados(const char* nomArchEmpl)
{
    Empleado empleados[CANT_EMPL] =
    {
        {8, "Juan Perez", 'M', {12, 2, 2005}, 240000},
        {5, "Javier Rodriguez", 'M', {12, 2, 2005}, 150000},
        {7, "Arnaldo Aguilar", 'M', {20, 4, 2008}, 130000},
        {2, "Bernardo Bargas", 'M', {12, 2, 2005} ,160000},
        {1, "Carlos Casares", 'M', {12, 2, 2005}, 120000},
        {3, "Dario Dado", 'M', {12, 2, 2005} , 170000},
        {4, "Estefania Estevez", 'F', {12, 2, 2005} ,160000},
        {6, "Fernanda Fernandez", 'F', {12, 2, 2005} , 150000}
    };

    FILE* arch = fopen(nomArchEmpl, "wb");

    if(!arch)
        return ERR_ARCH;

    fwrite(&empleados, sizeof(Empleado), CANT_EMPL, arch); /// estructura, tamaño estructura, cant. registros, puntero al archivo

    fclose(arch);

    return TODO_OK;
}

int mostrarArchivoEmpleados(const char* nomArchEmpl)
{
    FILE* arch = fopen(nomArchEmpl, "rb");

    if(!arch)
        return ERR_ARCH;

    Empleado empl;

    fread(&empl, sizeof(Empleado), 1, arch);

    while(!feof(arch))
    {
        printf("L: %03d N: %-20s S:%c F: %02d/%02d/%04d% S: %9.2f\n", empl.legajo, empl.nombre, empl.sexo, empl.fechaIng ,empl.sueldo);
        fread(&empl, sizeof(Empleado), 1, arch);
    }

    fclose(arch);

    return TODO_OK;
}

int convertirBinATxt(const char* nomArchBin, const char* nomArchTxt, size_t tamReg, BinATxt binATxt)
{
    void* reg = malloc(tamReg);

    if(!reg)
        return ERR_MEM;

    FILE* archBin = fopen(nomArchBin, "rb");
    if(!archBin)
    {
        free(reg);
        return ERR_ARCH;
    }

    FILE* archTxt = fopen(nomArchTxt, "wt");
    if(!archTxt)
    {
        fclose(archBin);
        free(reg);
        return ERR_ARCH;
    }

    fread(reg, tamReg, 1, archBin);

    while(!feof(archBin))
    {
        binATxt(reg, archTxt);
        fread(reg, tamReg, 1, archBin);
    }

    fclose(archBin);
    fclose(archTxt);

    free(reg);

    return TODO_OK;
}

int convertirTxTABin(const char* nomArchTxT, const char* nomArchBin, size_t tamReg , TxtABin txtABin)
{
    void* reg = malloc(tamReg);
    if(!reg)
        return ERR_MEM;

    FILE* archTxt = fopen(nomArchTxT, "rt");
    if(!archTxt)
    {
        free(reg);
        return ERR_ARCH;
    }

    FILE* archBin = fopen(nomArchBin, "wb");
    if(!archTxt)
    {
        fclose(archTxt);
        free(reg);
        return ERR_ARCH;
    }

    char linea[TAM_LINEA];
    int ret;

    fgets(linea, TAM_LINEA, archTxt);
    while(!feof(archTxt) && !errorGrave(ret))
    {
        ret = txtABin(linea, reg);

        if(ret == TODO_OK)
            fwrite(reg, tamReg, 1, archBin);

        fgets(linea, TAM_LINEA, archTxt);
    }

    fclose(archBin);
    fclose(archTxt);
    free(reg);
    return TODO_OK;
}

void empleadoBinATxtV(const void* reg, FILE* archTxt)
{
    const Empleado* empl = reg;

    fprintf
    (archTxt,
     "%d|%s|%c|%d/%d/%d|%.2f\n",
     empl->legajo,
     empl->nombre,
     empl->sexo,
     empl->fechaIng.dia, empl->fechaIng.mes, empl->fechaIng.anio,
     empl->sueldo
     );
}

void empleadoBinATxtF(const void* reg, FILE* archTxt)
{
    const Empleado* empl = reg;

    fprintf
    (archTxt,
     "%08d%-20s%c%02d%02d%04d%010.2f\n",
     empl->legajo,
     empl->nombre,
     empl->sexo,
     empl->fechaIng.dia, empl->fechaIng.mes, empl->fechaIng.anio,
     empl->sueldo
     );
}

int empleadoTxtFABin(char* linea, void* reg)
{
    Empleado* empl = reg;
    char* act = strchr(linea, '\n');
    if(!act)
        return ERR_LINEA_LARGA;

    *act = '\0';
    act -= 10;
    sscanf(act + 1, "%f", &empl->sueldo);

    *act = '\0';
    act -= 8;
    sscanf(act + 1, "%2d/%2d/%4d", &empl->fechaIng.dia, &empl->fechaIng.mes, &empl->fechaIng.anio);

    *act = '\0';
    act--;
    empl->sexo = *act;

    *act = '\0';
    act -= TAM_NOMBRE;
    strncpy(&empl->nombre, act + 1, TAM_NOMBRE);
    *(empl->nombre + TAM_NOMBRE) = '\0';

    *act = '\0';
    sscanf(linea, "%d", &empl->legajo);
}

int empleadoTxtVABin(char* linea, void* reg)
{
    Empleado* empl = reg;
    char* act = strchr(linea, '\n');
    if(!act)
        return ERR_LINEA_LARGA;

    *act = '\0';
    act = strrchr(linea, '|');
    sscanf(act + 1, "%f", &empl->sueldo);

    *act = '\0';
    act = strrchr(linea, '|');
    sscanf(act + 1, "%d/%d/%d", &empl->fechaIng.dia, &empl->fechaIng.mes, &empl->fechaIng.anio);

    *act = '\0';
    act = strrchr(linea, '|');
    empl->sexo = (*act - 1);

    *act = '\0';
    act = strrchr(linea, '|');
    strcpy(empl->nombre, act);

    *act = '\0';
    sscanf(linea, "%d", &empl->legajo);
}

bool errorGrave(int codigo)
{
    return codigo == ERR_LINEA_LARGA;
}
