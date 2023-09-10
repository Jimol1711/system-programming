#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eliminar(char *str, char *pat) {
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
        if (strncmp(str_copy, pat, patLen2) == 0) {
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

    // Se crea la variable dinámica para insertar el nuevo string, Se implementa eliminar en dicha variable dinámica
    char *nuevo_string = malloc(strlen(str)-(contador*strlen(pat))+1);
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
            *nuevo_string = *str;
            nuevo_string++;
            str++;
        }
    }
    *nuevo_string = '\0';

    return nuevo_string;
#endif
#if 0
    int result_length = 0;
    const char* str_ptr = str;
    
    // Calculate the length of the result string after removing the pattern
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
            result_length++;
            str_ptr++;
        }
    }
    
    // Allocate memory for the result string
    char* result = (char*)malloc(result_length + 1); // +1 for the null terminator
    
    // Copy the modified string to the dynamically allocated memory
    char* dest = result;
    str_ptr = str;
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
            *dest = *str_ptr;
            dest++;
            str_ptr++;
        }
    }
    
    *dest = '\0'; // Null-terminate the result string
    return result;
#endif
#if 0
    char *str_copia = malloc(strlen(str)+1);
    strcpy(str_copia,str);
    eliminar(str_copia,pat);
    return str_copia;
#endif
}

int main() {
    // Eliminar
    char str1[] = "111011001";
    char pat1[] = "10";

    printf("String original eliminar: %s\n", str1);
    printf("%d\n",strlen(str1));

    eliminar(str1, pat1);

    printf("String después de eliminar '%s': %s\n", pat1, str1);
    printf("%d\n",strlen(str1));

    printf("\n");
    // Eliminados
    char str2[] = "111011001";
    char pat2[] = "10";

    printf("String original eliminados: %s\n", str2);
    printf("%d\n",strlen(str2));

    char *str_eliminado = eliminados(str2,pat2);

    printf("String después de eliminados '%s': %s\n", pat2, str_eliminado);
    printf("%d\n",strlen(str_eliminado));
}