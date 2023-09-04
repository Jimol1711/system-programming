#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    // Se crea un puntero de destino para ir sobreescribiendo el string y uno temporal para recorrer el patrón
    char *dest = str;
    char *temp;       
    while (*str) {
        temp = pat;
        // La variable coincidencia se usa para determinar cuando se encontró una versión del patrón en el string, y así saltarsela
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
    int largo_resultante = 0;
    const char* str_ptr = str;
    
    // Calulamos largo del string resultante
    while (*str_ptr) {
        const char* temp = pat;
        int coincidencia = 1;
        while (*str_ptr == *temp && *temp != '\0') {
            str_ptr++;
            temp++;
        }
        if (*temp == '\0') {
            coincidencia = 0;
        }
        if (coincidencia) {
            largo_resultante++;
            str_ptr++;
        }
    }
    
    // Se crea variable dinámica para el string resultante, hago casteo para que no haya conflicto
    char* result = (char*)malloc(largo_resultante + 1);
    
    // Se copia el string a la variable dinámica
    char* dest = result;
    str_ptr = str;
    while (*str_ptr) {
        char* temp = pat;
        int coincidencia = 1;
        while (*str_ptr == *temp && *temp != '\0') {
            str_ptr++;
            temp++;
        }
        if (*temp == '\0') {
            coincidencia = 0;
        }
        if (coincidencia) {
            *dest = *str_ptr;
            dest++;
            str_ptr++;
        }
    } 
    *dest = '\0';
    return result;
}