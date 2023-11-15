#include <string.h>

// Función auxiliar que cuenta las palabras en un string
int contarPalabras(char *str1, char *str2) {
  int cont1 = 0;
  int cont2 = 0;
  int hayPal1 = 0;
  int hayPal2 = 0;

  while(*str1) {
    if (*str1 != ' ') {
      if (!hayPal1) {
        cont1++;
        hayPal1 = 1;
      }
    } else {
      hayPal1 = 0;
    }
    str1++;
  }

  while(*str2) {
    if (*str2 != ' ') {
      if (!hayPal2) {
        cont2++;
        hayPal2 = 1;
      }
    } else {
      hayPal2 = 0;
    }
    str2++;
  }

  return cont1 - cont2;
}

void sort(char **a, int n) {
  char **ult= &a[n-1];
  char **p= a;
  while (p<ult) {

    int t1= contarPalabras(p[0],p[1]);

    if (t1 <= 0)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= a;
    }
  }
}
