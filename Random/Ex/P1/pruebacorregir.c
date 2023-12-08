#include <stdio.h>

void corregir(char *s) {
    char *src = s;
    char *dest = s;

    while (*s) {
        if (*src == ' ') {
            src++;
        }

    *dest = '\0';
}

int main() {
    char s[] = " h o, l a , q , u e t ,a l";
    corregir(s);
    printf("Compila\n");

    printf("Result: %s\n", s);

    return 0;
}