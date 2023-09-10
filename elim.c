#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
#if 0
    char *dest = str;
    size_t patLen = strlen(pat);

    while (*str) {
        if (strncmp(str, pat, patLen) == 0) {
            str += patLen; // Saltar el patrón en str
        } else {
            *dest = *str;
            dest++;
            str++;
        }
    }

    *dest = '\0';
#endif
#if 1
    // Se crea un puntero de destino para ir sobreescribiendo el string y uno temporal para recorrer el patrón
    char *dest = str;
    while (*str) {
        // Si los caracteres coinciden, avanzamos en ambos strings
        if (*str == *pat) {
            char *temp_str = str;
            char *temp_pat = pat;
            int coincidencia = 1;
            
            // Comparamos los caracteres de str y pat hasta que pat llegue a su fin
            while (*temp_pat != '\0') {
                if (*temp_str != *temp_pat) { 
                    coincidencia = 0;
                    break;
                }
                temp_str++;
                temp_pat++;
            }
            
            // Si hay coincidencia, avanzamos el puntero en str
            if (coincidencia) {
                str = temp_str;
            }
        }
        
        // Copiamos el caracter actual de str al destino y avanzamos los punteros
        *dest = *str;
        dest++;
        str++;
    }
    
    *dest = '\0';
#endif
}

char *eliminados(char *str, char *pat) {
    int contador = 0;
    char *strcontar = str;
    while (*strcontar) {
        // Si los caracteres coinciden, avanzamos en ambos strings
        if (*strcontar == *pat) {
            char *temp_str = strcontar;
            char *temp_pat = pat;
            int coincidencia = 1;
            
            // Comparamos los caracteres de str y pat hasta que pat llegue a su fin
            while (*temp_pat != '\0') {
                if (*temp_str != *temp_pat) { 
                    coincidencia = 0;
                    break;
                }
                temp_str++;
                temp_pat++;
            }
            
            // Si hay coincidencia, avanzamos el puntero en str
            if (coincidencia) {
                contador++;
            }
        }
        strcontar++;
    }

    // Variable dinámica con malloc
    char *str_nuevo = malloc(strlen(str)-(contador*strlen(pat))+1);
    char *str_nuevo_nuevo = str_nuevo;
    char *str_crear = str;
    // Se crea un puntero de destino para ir sobreescribiendo el string y uno temporal para recorrer el patrón
    while (*str_crear) {
        // Si los caracteres coinciden, avanzamos en ambos strings
        if (*str_crear == *pat) {
            char *temp_str = str_crear;
            char *temp_pat = pat;
            int coincidencia = 1;
            
            // Comparamos los caracteres de str y pat hasta que pat llegue a su fin
            while (*temp_pat != '\0') {
                if (*temp_str != *temp_pat) { 
                    coincidencia = 0;
                    break;
                }
                temp_str++;
                temp_pat++;
            }
            
            // Si hay coincidencia, avanzamos el puntero en str
            if (coincidencia) {
                str_crear = temp_str;
            }
        }
        
        // Copiamos el caracter actual de str al destino y avanzamos los punteros
        *str_nuevo_nuevo = *str_crear;
        str_nuevo_nuevo++;
        str_crear++;
    }
    
    *str_nuevo_nuevo= '\0';
    
    return str_nuevo;
#if 0
    int largo = 0;
    char *dest = str;
    size_t patLen = strlen(pat);

    while (*str) {
        if (strncmp(str, pat, patLen) == 0) {
            continue; // Saltar el patrón en str
        } else {
            dest++;
            str++;
            largo++;
        }
    }
    *dest = '\0';

    char *str_copy = malloc(strlen(str)+1);
    strcpy(str_copy,str);

    char *dest2 = str_copy;
    size_t patLen2 = strlen(pat);

    while (*str) {
        if (strncmp(str_copy, pat, patLen) == 0) {
            str += patLen2; // Saltar el patrón en str
        } else {
            *dest2 = *str_copy;
            dest2++;
            str++;
        }
    }
    *dest2 = '\0';

    char *str_copy2 = malloc(strlen(str)-(largo*strlen(pat))+1);
    strcpy(str_copy2,str_copy);
    free(str_copy);
    return str_copy2;

#endif
#if 0
    char *str_copia = malloc(strlen(str)+1);
    strcpy(str_copia,str);
    // Calculo del largo del string
    int contador = 0;
    while (*str_copia) {
        if (*str_copia == *pat) {

            char *temp_str = str_copia;
            char *temp_pat = pat;
            int coincidencia = 1;

            while (*temp_pat != '\0') {

                if (*temp_str != *temp_pat) {
                    coincidencia = 0;
                    break;
                }

            temp_str++;
            temp_pat++;

            }

        if (coincidencia) {
            str_copia = temp_str;
            contador++;
            }

        }
        str_copia++;
    }   

    char *dest = str_copia;
    while (*str_copia) {
        
        if (*str_copia == *pat) {
            char *temp_str = str_copia;
            char *temp_pat = pat;
            int coincidencia = 1;
            
            while (*temp_pat != '\0') {
                if (*temp_str != *temp_pat) {
                    coincidencia = 0;
                    break;
                }
                temp_str++;
                temp_pat++;
            }

            if (coincidencia) {
                str_copia = temp_str;
            }
        }
        
        *dest = *str_copia;
        dest++;
        str_copia++;
    }
    *dest = '\0';

    return str_copia;
#endif
#if 0
    char *str_copy = malloc(strlen(str)+1);
    strcpy(str_copy,str);

    eliminar(str_copy,pat);

    char *str_copy2 = malloc(strlen(str_copy)+1);
    strcpy(str_copy2,str_copy);

    free(str_copy);

    return str_copy2;
#endif

}