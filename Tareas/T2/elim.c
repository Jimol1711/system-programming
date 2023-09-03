#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
  while (*str) {
    if (*pat == *str)
      printf(":D\n");
    str++;
  }
}

char *eliminados(char *str, char *pat) {
  char *ans = malloc(0);
  return ans;
}