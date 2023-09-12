#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    // Puntero de destino donde se va sobreescriendo el string sin el patrón
    char *dest = str; 
    
    while (*str) {
        // Esta constante funciona como booleano para determinar cuando existe una coincidencia del string
        int coincidencia = 1;
        
        // Se lee el patrón junto con el string usando punteros temporales
        for (char *temp_str = str, *temp_pat = pat; *temp_pat != '\0'; temp_str++, temp_pat++) {
            if (*temp_str != *temp_pat) {
                coincidencia = 0;
                break;
            }
        }
        
        if (coincidencia) {
            // Si hay coincidencia se avanza a la posición posterior al patrón, es decir, una cantidad de posiciones equivalentes al largo del patrón
            str += strlen(pat);
        } else {
            // Si no hay coincidencia se sobreescribe el caracter y se sigue avanzando
            *dest = *str;
            dest++;
            str++;
        }
    }
    *dest = '\0';
}

char *eliminados(char *str, char *pat) {
    // Dos copias del puntero str. Una para contar apariciones del patrón, la otra para almacenar el string nuevo en la variable dinámica
    char *copia_str = str;
    char *copia_str2 = str;

    // Contador de cantidad de veces que aparece el patrón para tener los bytes justos de memoria al llamar a malloc
    int contador = 0;
    
    while (*copia_str) {
        int coincidencia = 1;
        
        // Se lee el patrón junto con el string usando punteros temporales
        for (char *temp_str = copia_str, *temp_pat = pat; *temp_pat != '\0'; temp_str++, temp_pat++) {
            if (*temp_str != *temp_pat) {
                coincidencia = 0;
                break;
            }
        }
        
        if (coincidencia) {
            // Si hay coincidencia se avanza a la posición posterior al patrón, es decir, una cantidad de posiciones equivalentes al largo del patrón y se aumenta el contador
            copia_str += strlen(pat);
            contador++;
        } else {
            // Si no hay se sigue avanzandos
            copia_str++;
        }
    }

    // Copio eliminar con la memoria justa. Se agregan dos punteros más de destino, pero el segundo solo sirve para copiar en la variable dinámica
    char *dest2 = malloc(strlen(str)-(contador*strlen(pat))+1);
    char *dest22 = dest2;
    
    while (*copia_str2) {
        int coincidencia = 1;
        
        // Se lee el patrón junto con el string usando punteros temporales
        for (char *temp_str = copia_str2, *temp_pat = pat; *temp_pat != '\0'; temp_str++, temp_pat++) {
            if (*temp_str != *temp_pat) {
                coincidencia = 0;
                break;
            }
        }
        
        if (coincidencia) {
            // Se avanza después del patrón cuando hay una coincidencia
            copia_str2 += strlen(pat);
        } else {
            // Se copia al puntero que apunta a la variable dinámica
            *dest22 = *copia_str2;
            dest22++;
            copia_str2++;
        }
    }
    *dest22 = '\0';

    return dest2;
}