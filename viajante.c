#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "viajante.h"

int leer(int fd, void *vbuf, int n) {
  char *buf= vbuf;
  do {
    int rc= read(fd, buf, n);
    if (rc<=0)
      return 1; /* fracaso: error o fin del archivo/pipe/socket */
    n-= rc; /* descontamos los bytes leídos */
    buf+= rc; /* avanzamos el buffer para no reescribir lo leido previamente */
  } while (n>0); /* mientras no leamos todo lo que esperamos */
  return 0; /* exito */
}

double viajante_par(int z[], int n, double **m, int nperm, int p) {
  // Complete esta funcion
  // Puede invocar a su version secuencial: viajante
  // Use la funcion leer para que el padre reciba la ruta del hijo.
  // Use fork() para crear p nuevos procesos.  El padre solo obtiene los
  // resultados de los procesos hijos a traves de pipes, entierra a los
  // los hijos y calcula el resultado final.
  // Despues de invocar fork() agregue: srandom(getUSecsOfDay()*getpid());
  // Esto es para que cada proceso genere secuencias de numeros aleatorios
  // diferentes.

  // N° de permutaciones que hace cada hijo
  int npermh = nperm / p;
  // pids de los hijos
  int pids[p];
  // file descriptors
  int fds[p][2];
  // menor distancia hasta el momento
  double min = DBL_MAX;

  for(int i=0; i<p; i++) {
    pipe(fds[i]);
    pid_t pid = fork();
    int ruta[n+1];

    if(pid == 0) {
      close(fds[i][0]);
      srandom(getUSecsOfDay()*getpid());
      viajante(ruta, n, m, npermh);
      write(fds[i][1], &ruta, sizeof(ruta));
      exit(0);
    } else {
      close(fds[i][1]);
      pids[i] = pid;
      int res[n+1];
      leer(fds[i][0], &res, sizeof(res));
      srandom(getUSecsOfDay()*getpid());
      double minp = viajante(res, n, m, nperm);
      close(fds[i][0]);
      waitpid(pids[i], NULL, 0);
      if(minp < min) {
        min = minp;
      }
      z[i] = res[i];
    }
  }
  return min;
}
