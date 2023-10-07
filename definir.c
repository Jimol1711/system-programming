#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

// La función agregarDefinición recibe el diccionario, la palabra y su definción y la agrega al diccionario
int agregarDefinicion(char *nom_dic, char *pal, char *def) {
  FILE *arch = fopen(nom_dic, "r+");
  char buf[81];

  //Diagnóstico de errores usando perror
  if (arch == NULL) {
    perror("La llave %s ya se encuentra en el diccionario");
    return 0;
  }

  // Calculamos tamaño del archivo con fseek y ftell
  fseek(arch, 0, SEEK_END);
  long size = ftell(arch);
  fseek(arch, 0, SEEK_SET);

  // Calculamos el número de líneas
  int lineas = size / 81;

  // Calculamos donde debe estar la definición con hash
  int linea_def = hash_string(pal) % lineas;

  // Nos movemos a esa línea
  fseek(arch, linea_def * 81, SEEK_SET);

  // Buscamos la primera línea vacía con un loop
  while (fgets(buf, 82, arch) != NULL) {
    if (buf[0] == '\n') {
      fseek(arch, -81, SEEK_CUR);
      fprintf(arch, "%s:%s\n", pal, def);
      fclose(arch);
      return 0;
    }
    fseek(arch, 81, SEEK_CUR);
  }

  fseek(arch, 0, SEEK_SET);

  while (fgets(buf, 81, arch) != NULL) {
    if (buf[0] == '\n') {
      fseek(arch, -81, SEEK_CUR);
      fprintf(arch, "%s:%s\n", pal, def);
      fclose(arch);
      return 0;
    }
  }

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
