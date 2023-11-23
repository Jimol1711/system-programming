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
  // file descriptors de lectura
  int infds[p];
  // menor distancia hasta el momento
  double min = DBL_MAX;

  for(int i=0; i<p; i++) {
    int fds[2];
    pipe(fds);
    pid_t pid = fork();
    if(pid == 0) {
      pids[i] = pid;
      close(fds[0]);
      
      // Heurística
# if 0
      int minh;
      for(int i=0; i<=npermh; i++) {
        int x[(n+1)/p];
        srandom(getUSecsOfDay()*getpid());
        gen_ruta_alea(x,((n+1)/p)-1);
        double d = dist(x, ((n+1)/p)-1, m);
        if (d<min) {
          minh = d;
          for(int j=0; j<=((n+1)/p)-1; j++) {
            z[j] = x[j];
          }
        }
      }
#endif
      write(fds[1],&minh,sizeof(double));
      exit(1);
    } else {
      close(fds[1]);
      infds[i] = fds[0];
      pids[i] = pid;
    }
  }

  // Se entierra a los hijos
  for(int i=0; i<p; i++) {
    double res;
    leer(infds[i],&res,sizeof(double));
    close(infds[i]);
    waitpid(pids[i],NULL,0);
    if(res != 0) {
      min = res;
    }
  }
  return min;
}
