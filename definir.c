#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

// La función agregarDefinición recibe el diccionario, la palabra y su definción y la agrega al diccionario
int agregarDefinicion(char *nom_dic, char *pal, char *def) {
  FILE *arch = fopen(nom_dic, "r+");
  char buf[81];

  // Calculamos tamaño del archivo con fseek y ftell
  fseek(arch, 0, SEEK_END);
  long size = ftell(arch);
  fseek(arch, 0, SEEK_SET);

  // Calculamos el número de líneas
  int lineas = size / 80;

  // Calculamos donde debe estar la definición con hash
  int linea_def = hash_string(pal) % lineas;

  // Nos movemos a esa línea
  fseek(arch, linea_def * 80, SEEK_SET);

  // Buscamos la primera línea vacía con un loop
  while (fgets(buf, sizeof(buf), arch) != NULL) {
    if (buf[0] == '\n') {
      fseek(arch, -82, SEEK_CUR);
      fprintf(arch, "%s:%s\n", pal, def);
      fclose(arch);
      return 0;
    }
  }

  fseek(arch, 0, SEEK_SET);

  while (fgets(buf, sizeof(buf), arch) != NULL) {
    if (buf[0] == '\n') {
      fseek(arch, -82, SEEK_CUR);
      fprintf(arch, "%s:%s\n", pal, def);
      fclose(arch);
      return 0;
    }
  }

  // Si llegamos aquí no se encontró una línea vacía
  fclose(arch);
  return 0;
}

int main(int argc, char *argv[]) {

  char *nom_dic = argv[1];
  char *pal = argv[2];
  char *def = argv[3];

  agregarDefinicion(nom_dic, pal, def);

  return 0;

}
