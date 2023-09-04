#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    char *dest = str;
    char *temp;       
    while (*str) {
        temp = pat;
        int coincidencia = 1;
        while (*str == *temp && *temp != '\0') {
            str++;
            temp++;
        }
        if (*temp == '\0') {
            coincidencia = 0;
        }
        if (coincidencia) {
            *dest = *str;
            dest++;
            str++;
        }
    }
    *dest = '\0';
}

char *eliminados(char *str, char *pat) {
#if 1
    char *dest = str;
    char *temp; 

    int contador = 0; // Se cuenta el número de veces que aparece el patrón   
    while (*str) {
        temp = pat;
        while (*str == *temp && *temp != '\0') {
            str++;
            temp++;
        }
        if (*temp == '\0') {
            contador += 1;
        }
    }

    char *nuevo_string = malloc(strlen(str)-(contador*strlen(pat))+1);

    
#endif
}