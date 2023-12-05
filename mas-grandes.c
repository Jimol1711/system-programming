#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pss.h"
       
// Estructura para guardar nombre y tamanno
typedef struct {
  char *filename;
  off_t size;
} FileInfo;

// Cola global
Queue *queue;
int queueSize;
FileInfo **fileArray;

void addToQueue(const char *filename) {
    struct stat fileStat;

    if (stat(filename, &fileStat) == 0 && S_ISREG(fileStat.st_mode)) {
        FileInfo *fileInfo = (FileInfo *)malloc(sizeof(FileInfo));
        fileInfo->filename = strdup(filename);
        fileInfo->size = fileStat.st_size;
        put(queue, (void *)fileInfo);
    }
}

int recorrerDir(const char *dir) {

  // Recorrido de los contenidos del directorio en inserción de archivos en la cola
  
}

// Función de comparación para sortPtrArray
int compareFileSize(const void *a, const void *b) {
    const FileInfo *fileA = *(const FileInfo **)a;
    const FileInfo *fileB = *(const FileInfo **)b;

    // Comparar por tamnno de archivo
    return fileB->size - fileA->size;
}

int main(int argc, char *argv[]) {

  queue = makeQueue();

  // Tamanno de la cola
  queueSize = queueLength(queue);

  // Arreglo para insertar la información de la cola
  FileInfo **fileArray = (FileInfo **)malloc(queueSize * sizeof(FileInfo *));

  // Transferir los elementos de la cola al arreglo
  for (int i = 0; i < queueSize; ++i) {
    fileArray[i] = (FileInfo *)get(queue);
  }

  // Ordenar el arreglo por tamaño de archivo
  sortPtrArray(fileArray, 0, queueSize - 1, compareFileSize);

  // Mostrar los n archivos más grandes
  for (int i = 0; i < atoi(argv[2]) && i < queueSize; ++i) {
      printf("%s %ld\n", fileArray[i]->filename, fileArray[i]->size);
  }

  // Liberar memoria utilizada
  for (int i = 0; i < queueSize; ++i) {
      free(fileArray[i]->filename);
      free(fileArray[i]);
  }

  return 0;

}
