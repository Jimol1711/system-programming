#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include "pss.h"
       
// Estructura para guardar nombre y tamanno
typedef struct {
  char *filename;
  off_t size;
} FileInfo;

// Variables globales
Queue *queue;
int queueSize;
FileInfo **fileArray;

// Función que recorre en profundidad y guarda en la cola
void recorrerDir(char *nom) {
  struct stat st_nom;
  stat(nom, &st_nom);
  
  if (S_ISREG(st_nom.st_mode)) {
    // Es un archivo regular
    char *str_dup = strdup(nom);
    off_t newSize = st_nom.st_size;
    FileInfo *fileInfo = (FileInfo *)malloc(sizeof(FileInfo));
    fileInfo->filename = str_dup;
    fileInfo->size = newSize;
    put(queue,fileInfo);
  }
  else if (S_ISDIR(st_nom.st_mode)) {
    // Es un directorio
    DIR *dir = opendir(nom);
    for (struct dirent *entry = readdir(dir);
         entry != NULL;
         entry = readdir(dir)) {
      if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0) {
        continue;
      }
      char *fullPath = malloc(strlen(nom) + strlen(entry->d_name) + 2);
      strcpy(fullPath, nom);
      strcat(fullPath, "/");
      strcat(fullPath, entry->d_name);
      recorrerDir(fullPath);
      free(fullPath);
    }
    closedir(dir);
  } else {
    // Podria ser un dispositivo, un link simbolico, etc.
    fprintf(stderr, "Archivo %s es de tipo desconocido\n", nom);
    exit(1);
  }
}

// Función de comparación para sortPtrArray
int compareFileSize(void *ptr, int a, int b) {
  FileInfo *fileA = ((FileInfo **)ptr)[a];
  FileInfo *fileB = ((FileInfo **)ptr)[b];

  // Comparar por tamaño de archivo
  if (fileA->size != fileB->size) {
    // Si los tamaños son diferentes, compara por tamaño
    return (int)(fileB->size - fileA->size);
  } else {
    // Si los tamaños son iguales, compara lexicográficamente
    return strcmp(fileA->filename, fileB->filename);
  }
}

int main(int argc, char *argv[]) {
  queue = makeQueue();

  if (argc != 3) {
    fprintf(stderr, "Uso: %s <directorio> <n>\n", argv[0]);
    return 1;
  }

  recorrerDir(argv[1]);

  // Tamanno de la cola
  queueSize = queueLength(queue);

  // Arreglo para insertar la información de la cola
  fileArray = (FileInfo **)malloc(queueSize * sizeof(FileInfo *));

  // Transferir los elementos de la cola al arreglo
  for (int i = 0; i < queueSize; i++) {
    fileArray[i] = (FileInfo *)get(queue);
  }

  // Ordenar el arreglo por tamaño de archivo
  sortPtrArray(fileArray, 0, queueSize - 1, compareFileSize);

  // Mostrar los n archivos más grandes
  for (int i = 0; i < atoi(argv[2]) && i < queueSize; ++i) {
      printf("%s %ld\n", fileArray[i]->filename, fileArray[i]->size);
  }

  // Liberación de memoria
  for (int i = 0; i < queueSize; ++i) {
    free(fileArray[i]->filename);
    free(fileArray[i]);
  }

  free(fileArray);

  return 0;

}
