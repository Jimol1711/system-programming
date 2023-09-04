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
    char *temp;  
    int contador = 0;   
    while (*str) {
        temp = pat;
        int coincidencia = 1;
        while (*str == *temp && *temp != '\0') {
            str++;
            temp++;
        }
        if (*temp == '\0') {
            coincidencia = 0;
            contador += 1;
        }
        if (coincidencia) {
            str++;
        }
    }

    str--;

    // Se crea la variable dinámica para insertar el nuevo string, Se implementa eliminar en dicha variable dinámica
    char *espacio = malloc(strlen(str)-(contador*strlen(pat))+1);
    char *nuevo_str2 = espacio;
    char *temp2;       
    while (*str) {
        temp2 = pat;
        int coincidencia = 1;
        while (*str == *temp2 && *temp2 != '\0') {
            str++;
            temp2++;
        }
        if (*temp2 == '\0') {
            coincidencia = 0;
        }
        if (coincidencia) {
            *nuevo_str2 = *str;
            nuevo_str2++;
            str++;
        }
    }
    nuevo_str2--;
    strcpy(espacio,nuevo_str2);

    return espacio;
#endif
}