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

  // Se calcula tamaño del diccionario y número de líneas
  fseek(arch, 0, SEEK_END);
  int size = ftell(arch);
  int numLineas = size / 81;

  // Se calcula línea a poner la definción con hash y se mueve el cursor a esa línea
  int numDef = hash_string(pal) % numLineas;

  char buf[81];
  fseek(arch, numDef * 81, SEEK_SET);

  // Lógica para agregar la definición, usando fread
  while(fread(buf, 81, 1, arch) != 0) {
    if (buf[0] == ' ') { 
      fseek(arch, -81, SEEK_CUR);
      if (fgetc(arch) == ' ') {
        fseek(arch, -1, SEEK_CUR);
        fputs(pal, arch);
        fputc(':', arch);
        fputs(def, arch);
        fclose(arch);
        return 0;
      } // Diagnóstico de error, llave ya se encuentra definida
    } else if (strncmp(buf,pal,strlen(pal)) == 0) {
      fprintf(stderr, "La llave %s ya se encuentra en el diccionario\n", pal);
      fclose(arch);
      return 1;
    }
  }

  char buf_[81];

  // Si se salió del while anterior se llego al final del archivo, por lo que se vuelve al comienzo hasta encontrar línea vacía
  fseek(arch, 0, SEEK_SET);

  while(fread(buf_, 81, 1, arch) != 0) {
    if (buf_[0] == ' ') {
      fseek(arch, -81, SEEK_CUR);
      if (fgetc(arch) == ' ') {
        fseek(arch, -1, SEEK_CUR);
        fputs(pal, arch);
        fputc(':', arch);
        fputs(def, arch);
        fclose(arch);
        return 0;
      }
    } else if (strncmp(buf_,pal,strlen(pal)) == 0) {
      fprintf(stderr, "La llave %s ya se encuentra en el diccionario\n", pal);
      fclose(arch);
      return 1;
    }
  }

  // No se encontró línea vacía. Diagnóstico de error, el diccionario está lleno
  fprintf(stderr, "dicc-full.txt: el diccionario esta lleno\n");
  fclose(arch);
  return 1;
}
