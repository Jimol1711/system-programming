#include <string.h>

void sort(char **noms, int n) {
  char **ult= &noms[n-1];
  char **p= noms;
  while (p<ult) {
    char *ap1 = p[0];
    char *ap2 = p[1];

    while (*ap1 != ' ') {
      ap1++;
    }
    while (*ap2 != ' ') {
      ap2++;
    }
    ap2++;

    int result = strcmp(ap1, ap2);

    if (result == 0) {
      if (strcmp(p[0],p[1])<= 0)
        p++;
      else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= noms;
      }
    } else if (result < 0) {
      p++;
    } else {
      char *tmp = p[0];
      p[0] = p[1];
      p[1] = tmp;
      p= noms;
    }
  }
}
