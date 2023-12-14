#include <stdio.h>

void corregir(char *s) {
    char *src = s;
    char *dest = s;

    while (*src) {
        if (*src == ' ' && *(src + 1) && *(src + 1) == ',') {
            src++; // Skip the space
        } else {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';
}

int main() {
    char s[] = " h o   , l a  , q , u e t ,a l";
    corregir(s);

    printf("Result: %s\n", s);

    return 0;
}