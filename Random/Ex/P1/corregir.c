#include <string.h>
#include <stdlib.h>

#include "corregir.h"

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

  if (*(dest - 1) == ',') {
      *dest = '\0'; // Remove trailing space before null terminator if needed
  } else {
      *dest = '\0';
  }
}  
