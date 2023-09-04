#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    char *dest = str;
    char *temp;       
    while (*str) {
        temp = pat;
        while (*str == *temp && *temp != '\0') {
            str++;
            temp++;
        }
        if (*temp == '\0') {
            continue;
        }
        *dest = *str;
        dest++;
        str++;
    }
    *dest = '\0';
}

char *eliminados(char *str, char *pat) {
#if 1
    // Variables para contar la longitud del resultado
    int result_length = 0;
    char *temp = str;

    // Calcular la longitud del resultado
    while (*temp) {
        char *temp2 = pat;
        int match = 1;
        
        // Comprobar si se encuentra 'pat' a partir de la posición actual de 'temp'
        while (*temp2) {
            if (*temp != *temp2) {
                match = 0;
                break;
            }
            temp++;
            temp2++;
        }

        if (!match) {
            result_length++;
        }
    }

    // Asignar memoria dinámica para el resultado
    char *result = (char *)malloc(result_length + 1); // +1 para el carácter nulo

    // Copiar los caracteres que no coinciden con 'pat' en 'result'
    temp = str;
    char *dest = result;
    
    while (*temp) {
        char *temp2 = pat;
        int match = 1;
        
        // Comprobar si se encuentra 'pat' a partir de la posición actual de 'temp'
        while (*temp2) {
            if (*temp != *temp2) {
                match = 0;
                break;
            }
            temp++;
            temp2++;
        }

        if (!match) {
            *dest = *temp;
            dest++;
        }
        else {
            temp++;
        }
    }

    // Agregar un carácter nulo al final de 'result'
    *dest = '\0';

    return result;
#endif
}