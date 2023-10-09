#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

int main(int argc, char *argv[]) {

  char *nom_dic = argv[1];
  char *pal = argv[2];
  char *def = argv[3];
  int tamPal = strlen(pal);

  FILE *arch = fopen(nom_dic, "r+");
  if (arch==NULL) {
    perror(nom_dic);
    exit(1);
  }

  fseek(arch, 0, SEEK_END);
  int size = ftell(arch);
  int numLineas = size / 81;

  int numDef = hash_string(pal) % numLineas;

  char buf[81];
  fseek(arch, numDef * 81, SEEK_SET);

  while(fgets(buf, 81, arch) != NULL) {
    if(strncmp(buf, pal, tamPal)==0){
      fprintf(stderr, "La llave %s ya se encuentra en el diccionario", pal);
      fclose(arch);
      exit(2);
    }
    if (buf[0] == '\n') {
      fseek(arch, -81, SEEK_CUR);
      fputs(pal, arch);
      fputc(':', arch);
      fputs(def, arch);
      fclose(arch);
      return 0;
    }
  }

  fseek(arch, 0, SEEK_SET);

  while(fgets(buf, 81, arch) != NULL) {
    if(strncmp(buf, pal, tamPal)==0){
      fprintf(stderr, "La llave %s ya se encuentra en el diccionario", pal);
      fclose(arch);
      exit(2);
    }
    if (buf[0] == '\n') {
      fseek(arch, -81, SEEK_CUR);
      fputs(pal, arch);
      fputc(':', arch);
      fputs(def, arch);
      fclose(arch);
      return 0;
    }
  }

  fprintf(stderr, "El diccionario está lleno");
  fclose(arch);
  return 0;

}