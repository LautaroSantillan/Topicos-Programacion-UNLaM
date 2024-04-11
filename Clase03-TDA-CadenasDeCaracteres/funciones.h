#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> /// Para toupper() y tolower()

#define TAM 100

char* normalizarCadena(char* cadNormalizada, const char* cadANormalizar);
bool esLetra(char car); // int is_alpha(char);
char aMayus(char car);
char aMinus(char car);
/*
int myStrlen(const char* cad);
char* myStrcpy(char* cadDest, const char* cadOrig);
char* myStrstr(const char* cad, const char* subCad);
char* myStrcat(char* cad1, const char* cad2);*/
