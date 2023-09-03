#include <stdio.h>

void eliminar(char *str, char *pat) {
  char *dest = str;
  char *temp;
  while (*str) {
    temp = pat;
    while (*str == *temp && *temp != '\0')
    str++;
    temp++;
    if (*temp == '\0') {
    continue;
    }
    *dest = *str;
    dest++;
    str++;
  }
  *dest = '\0';
}

int main() {
    char str[] = "Esto es una prueba de patpatpat eliminación.";
    const char pat[] = "p";

    printf("String original: %s\n", str);

    eliminar(str, pat);

    printf("String después de eliminar '%s': %s\n", pat, str);

    return 0;
}