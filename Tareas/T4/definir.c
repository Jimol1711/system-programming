#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

int main(int argc, char *argv[]) {

  // Diagnóstico de error, número incorrecto de argumentos
  if (argc != 4) {
    fprintf(stderr, "Uso: ./definir <diccionario> <llave> <definicion>\n");
    exit(1);
  }

  char *nom_dic = argv[1];
  char *pal = argv[2];
  char *def = argv[3];

  // Se abre el archivo. Se diagnostica caso en que el archivo no existe
  FILE *arch = fopen(nom_dic, "r+");
  if (arch==NULL) {
    perror(nom_dic);
    exit(2);
  }

  // Diagnóstico de error, la llave ya se encuentra definida en el diccionario
  char buf_[81];

  while(fgets(buf_, strlen(pal)+1, arch)) {
    if(strcmp(buf_,pal) == 0) {
      fprintf(stderr, "La llave %s ya se encuentra en el diccionario\n", pal);
      fclose(arch);
      return 1;
    }
  }

  // Se calcula tamaño del diccionario y número de líneas
  fseek(arch, 0, SEEK_END);
  int size = ftell(arch);
  int numLineas = size / 81;

  // Se calcula línea a poner la definción con hash y se mueve el cursos a esa línea
  int numDef = hash_string(pal) % numLineas;

  char buf[81];
  fseek(arch, numDef * 81, SEEK_SET);

  // Lógica para agregar la definición
  while(fread(buf,82,1,arch)>0) { // fgets(buf, 81, arch) != NULL
    if (buf[0] == '\n') {
      fseek(arch, -81, SEEK_CUR);
      if (fgetc(arch) == ' ') {
        fseek(arch, -1, SEEK_CUR);
        fputs(pal, arch);
        fputc(':', arch);
        fputs(def, arch);
        fclose(arch);
        return 0;
      } else {
          fseek(arch, 80, SEEK_CUR);
          fputs(pal, arch);
          fputc(':', arch);
          fputs(def, arch);
          fclose(arch);
          return 0;
        }
      }
  }

  // Si se salió del while anterior se llego al final del archivo, por lo que se vuelve al comienzo hasta encontrar línea vacía
  fseek(arch, 0, SEEK_SET);

  while(fread(buf,82,1,arch)>0) {
    if (buf[0] == '\n') {
      fseek(arch, -81, SEEK_CUR);
      if (fgetc(arch) == ' ') {
        fseek(arch, -1, SEEK_CUR);
        fputs(pal, arch);
        fputc(':', arch);
        fputs(def, arch);
        fclose(arch);
        return 0;
      } else {
          fseek(arch, 80, SEEK_CUR);
          fputs(pal, arch);
          fputc(':', arch);
          fputs(def, arch);
          fclose(arch);
          return 0;
        }
    }
  }

  // No se encontró línea vacía. Diagnóstico de error, el diccionario está lleno
  fprintf(stderr, "dicc-full.txt: el diccionario está lleno\n");
  fclose(arch);
  return 0;

}