#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

// La función agregarDefinición recibe el diccionario, la palabra y su definción y la agrega al diccionario
int agregarDefinicion(char *nom_dic, char *pal, char *def) {
  FILE *arch = fopen(nom_dic, "r+");
  char buf[81];

  if (arch == NULL) {
    perror("Error abriendo el archivo");
    return 1;
  }
 
  // Calculamos tamaño del archivo con fseek y ftell
  fseek(arch, 0, SEEK_END);
  long size = ftell(arch);

  // Calculamos el número de líneas
  int lineas = size / 81;

  // Calculamos donde debe estar la definición con hash
  int linea_def = hash_string(pal) % lineas;

  // Nos movemos a esa línea
  fseek(arch, linea_def * 81, SEEK_SET);

  // Buscamos la primera línea vacía con un loop
  while (fgets(buf, sizeof(buf), arch) != NULL) {
    if (buf[0] == '\n') {
      fseek(arch, -81, SEEK_CUR);
      fputs(pal, arch);
      fputc(':', arch);
      fputs(def, arch);
      fclose(arch);
      return 0;
    }
    fseek(arch, 81 - ftell(arch), SEEK_CUR);
  }

  // Si se llega al final del archivo en el loop, se sale del while y se vuelve al comienzo
  fseek(arch, 0, SEEK_SET);

  // Se repite el proceso
  while (fgets(buf, sizeof(buf), arch) != NULL) {
    if (buf[0] == '\n') {
      fseek(arch, -81, SEEK_CUR);
      fputs(pal, arch);
      fputc(':', arch);
      fputs(def, arch);
      fclose(arch);
      return 0;
    } 
    fseek(arch, 81 - ftell(arch), SEEK_CUR);
  }

  // Si llegamos aquí no se encontró una línea vacía, el archivo está lleno
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
