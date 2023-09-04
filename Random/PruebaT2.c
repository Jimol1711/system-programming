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
}

int main() {
    // Eliminar
    char str1[] = "a";
    char pat1[] = "b";

    printf("String original eliminar: %s\n", str1);
    printf("%d\n",strlen(str1));

    eliminar(str1, pat1);

    printf("String después de eliminar '%s': %s\n", pat1, str1);
    printf("%d\n",strlen(str1));

    printf("\n");
    // Eliminados
    char str2[] = "a";
    char pat2[] = "b";

    printf("String original eliminados: %s\n", str2);
    printf("%d\n",strlen(str2));

    char *str_eliminado = eliminados(str2,pat2);

    printf("String después de eliminados '%s': %s\n", pat2, str_eliminado);
    printf("%d\n",strlen(str_eliminado));
}