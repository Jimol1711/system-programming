#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

// La función agregarDefinición recibe el diccionario, la palabra y su definción y la agrega al diccionario
int agregarDefinicion(char *nom_dic, char *pal, char *def) {
  FILE *arch = fopen(nom_dic, "r+");
  char buf[81];

  // Diagnóstico de error con perror, el archivo no existe
  if (arch == NULL) {
    perror("El archivo no existe");
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
  while (fread(buf, 1, 80, arch) > 0) {
    if (strncmp(buf, pal, strlen(pal)) == 0) {
      // Diagnóstico de error en el que la llave ya está en el diccionario
      fprintf(stderr, "La llave %s ya se encuentra en el diccionario", pal);
      fclose(arch);
      return 1;
    }
    else if (fgetc(arch) == '\n') {
      fseek(arch, -81, SEEK_CUR);
      fputs(pal, arch);
      fputc(':', arch);
      fputs(def, arch);
      fclose(arch);
      return 0;
    }
  }

  // Si se llega al final del archivo en el loop, se sale del while y se vuelve al comienzo
  fseek(arch, 0, SEEK_SET);

  // Se repite el proceso
  while (fread(buf, 1, 80, arch) > 0) {
    if (strncmp(buf, pal, strlen(pal)) == 0) {
      // Diagnóstico de error en el que la llave ya está en el diccionario
      fprintf(stderr, "La llave %s ya se encuentra en el diccionario", pal);
      fclose(arch);
      return 1;
    }
    else if (fgetc(arch) == '\n') {
      fseek(arch, -81, SEEK_CUR);
      fputs(pal, arch);
      fputc(':', arch);
      fputs(def, arch);
      fclose(arch);
      return 0;
    }
  }

  // Si llegamos aquí no se encontró una línea vacía, el archivo está lleno
  fprintf(stderr, "El diccionario está lleno");
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
