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

  // pids de los hijos
  int pids[p];
  // file descriptors
  int fds[p][2];
  // menor distancia hasta el momento
  double min = DBL_MAX;

  // Se lanza fork p veces
  for(int i=0; i<p; i++) {
    pipe(fds[i]);
    pid_t pid = fork();
    srandom(getUSecsOfDay()*getpid());

    if(pid == 0) { // Proceso hijo
      close(fds[i][0]);
      double minh = viajante(z, n, m, nperm/p);
      write(fds[i][1], &minh, sizeof(double));
      write(fds[i][1], z, sizeof(int) * (n+1));
      exit(0);
    } else { // Proceso padre
      close(fds[i][1]);
      pids[i] = pid;
    }
  }

  for (int i=0; i<p; i++) { // Proceso padre lee y entierra a los hijos
    double minp;
    leer(fds[i][0], &minp, sizeof(double));
    if(minp <= min) {
      min = minp;
      leer(fds[i][0], z, sizeof(int) * (n+1));
    }
    close(fds[i][0]);
    waitpid(pids[i], NULL, 0);
  }
  return min;
}
