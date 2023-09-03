#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eliminar(char *str, char *pat) {
  if (str == NULL || pat == NULL) {
        return;  // Verificar si los punteros son válidos
    }

    char *dest = str; // Puntero de destino para eliminar 'pat'
    char *temp;       // Puntero temporal para buscar 'pat'

    while (*str) {
        temp = pat;

        // Comprobar si se encuentra 'pat' a partir de la posición actual de 'str'
        while (*str == *temp && *temp != '\0') {
            str++;
            temp++;
        }

        // Si 'temp' llegó al final de 'pat', hemos encontrado una coincidencia
        if (*temp == '\0') {
            continue;  // Saltar 'pat' en 'str'
        }

        // Si no hay coincidencia, copiar el carácter a 'dest'
        *dest = *str;
        dest++;
        str++;
    }

    // Agregar un carácter nulo al final para marcar el nuevo final de 'str'
    *dest = '\0';
}

void eliminados(char *str, char *pat) {
    if (str == NULL || pat == NULL) {
        return;  // Verificar si los punteros son válidos
    }

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
}

int main() {

    char str1[] = "Esto es una prueba de patpatpat eliminación.";
    char pat1[] = "pat";

    printf("String original: %s\n", str1);

    eliminar(str1, pat1);

    printf("String después de eliminar '%s': %s\n", pat1, str1);

    char str2[] = "This is a test string with test pattern.";
    char pat2[] = "test";

    eliminados(str2, pat2);
    
    printf("Resultado: %s\n", str2);

    return 0;
}