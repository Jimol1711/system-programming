#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int eliminados(char *str, char *pat) {
#if 0
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

    if (result == NULL) {
        // Manejar el error de asignación de memoria
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        exit(1);
    }

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

    // Copiar el resultado de vuelta a 'str'
    strcpy(str, result);

    // Liberar la memoria dinámica
    free(result);
#endif
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
    //*dest = '\0';
    printf("%d\n",contador);
    return 0;
}

int main() {

    char str1[] = "hhhhhhh";
    char pat1[] = "h";

    printf("String original: %s\n", str1);
    printf("%d\n",strlen(str1));

    eliminar(str1, pat1);

    printf("String después de eliminar '%s': %s\n", pat1, str1);
    printf("%d\n",strlen(str1));

    eliminados("oaoaoaoaoaoaoaoa","o");

#if 0
    char str2[] = "This is a test string with test pattern.";
    char pat2[] = "test";

    eliminados(str2, pat2);
    
    printf("Resultado: %s\n", str2);

    return 0;
#endif
}