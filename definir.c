#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

// La función agregarDefinición recibe el diccionario, la palabra y su definción y la agrega al diccionario
void agregaDefinicion(char *nom_dic, char *pal, char *def) {
  FILE *f = fopen(nom_dic, "r+");
  char buf[82];

  //Diagnóstico de errores usando perror si no hay un archivo o la palabra y definición usan más de 80 caracteres
  if (f == NULL || (strlen(pal) + strlen(def)) >= 79) {
    perror("No se puede leer el archivo");
  }

  // Calculamos tamaño del archivo con fseek y ftell
  fseek(f, 0, SEEK_END);
  long size = ftell(f);

  // Calculamos el número de líneas
  int lineas = 0;


}

int main(int argc, char *argv[]) {
  // ... programe aca su solucion ...
}
