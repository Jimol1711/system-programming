#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
  //...
  for (int i=0; i<strlen(str)-1; i++) {
    char *caracter_str = str + i;
    for (int j=0; j<strlen(pat)-1; j++){
    char *caracter_pat = pat + j;
    if (caracter_str == caracter_pat){
      
    }
    }
  }
}

char *eliminados(char *str, char *pat) {
  //...
}
