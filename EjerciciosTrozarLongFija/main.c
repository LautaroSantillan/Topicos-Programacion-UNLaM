#include <stdio.h>
#include <string.h>

#define NUM_LENGTH 4
#define NAME_LENGTH 10
#define SALARY_LENGTH 6
#define RECORD_LENGTH (NUM_LENGTH + NAME_LENGTH + SALARY_LENGTH)

typedef struct {
    char num[NUM_LENGTH + 1];
    char name[NAME_LENGTH + 1];
    char salary[SALARY_LENGTH + 1];
} Registro;

void trozarRegistroFijo(char* linea, Registro* reg) {
    strncpy(reg->num, linea, NUM_LENGTH);
    reg->num[NUM_LENGTH] = '\0';

    strncpy(reg->name, linea + NUM_LENGTH, NAME_LENGTH);
    reg->name[NAME_LENGTH] = '\0';

    strncpy(reg->salary, linea + NUM_LENGTH + NAME_LENGTH, SALARY_LENGTH);
    reg->salary[SALARY_LENGTH] = '\0';
}

int main() {
    char linea[RECORD_LENGTH + 1] = "1234John Doe  045000";
    Registro reg;
    trozarRegistroFijo(linea, &reg);

    printf("Numero: %s\n", reg.num);
    printf("Nombre: %s\n", reg.name);
    printf("Salario: %s\n", reg.salary);

    return 0;
}
