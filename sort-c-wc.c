#include <string.h>

// Función auxiliar que cuenta las palabras en un string
int contarPalabras(char *str) {
  int cont = 0;
  int hayPal = 0;
  while(*str) {
    if (*str != ' ') {
      if (!hayPal) {
        cont++;
        hayPal = 1;
      }
    } else {
      hayPal = 0;
    }
    str++;
  }
  return cont;
}

void sort(char **a, int n) {
  char **ult= &a[n-1];
  char **p= a;
  while (p<ult) {

    int t1= contarPalabras(p[0]);
    int t2= contarPalabras(p[1]);

    if (t1 <= t2)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= a;
    }
  }
}
