#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int leer(int fd, void *buf, int n) {

    if (n==0) {
        return 0;
    }

    do {
        int rc = read(fd, buf, n);
        if (rc<=0) {
            return 1;
        }
        n -= rc; 
        buf = (char*)buf + rc;
    } while (n>0);

    return 0;
    
}

// Versión no paralelizada
int palindro(int *a, int n) {
    for (int i= 0; i<n/2; i++) {
        if (a[i] != a[n-1-i]) {
            return i;
        }
    }
    return n;
}

// Versión paralelizada
int palindro_par(int *a, int n, int p) {

    int step = (n/2) / p; // Definimos el paso a dar en cada subintervalo
    int pids[p]; // pids de los hijos
    int lfds[p]; // file descriptors de lectura
    int obt_padre;

    for (int i = 0; i < p; i++) { // Se lanzan p procesos
        int fds[2];
        pipe(fds);
        int pid = fork();
        if (pid == 0) {
            close(fds[0]);
            int init = step * i; // Definimos inicio y fin del intervalo a verificar
            int fin = step * (i+1);
            int in_hijo = n;
            for (int i = init; i < fin; i++) {
                if (a[i] != a[n-1-init]) {
                    in_hijo = i;
                } 
            }
            write(fds[1], &in_hijo, sizeof(int)); // Escribimos y hacemos exit
            exit(0);
        } else {
            close(fds[1]);
            lfds[i] = fds[0];
            pids[i] = pid;
        }
    }
    for (int i = 0; i < p; i++) { // Leemos de los hijos y los enterramos
        int in_padre;
        leer(lfds[i], &in_padre, sizeof(int));
        close(lfds[i]);
        waitpid(pids[i], NULL, 0);

        obt_padre = in_padre;
        if (obt_padre >= n/2) {
            break;
        }
    }
    return obt_padre;
} 


int main(int argc, char *argv[]) {

    int arreglo1[11] = {1,2,3,4,45,4,6,4,3,2,1};
    int arreglo2[9] = {2,1,2,3,5,3,2,1,2};

    // Versión no paralelizada
    if (palindro(arreglo1, 5)!=5 && palindro(arreglo2, 5) == 5) {
        printf("Caso malo está bien, da %d\n", palindro(arreglo1, 5));
        printf("Caso bueno está bien, da %d\n", palindro(arreglo2, 5));
    } else {
        printf("Está mal, da %d en el caso malo\n", palindro(arreglo1, 5));
        printf("Da %d en el caso buen\n", palindro(arreglo1, 5));
    }

        // Versión paralelizada
    if (palindro_par(arreglo1, 11, 4) == 0 && palindro_par(arreglo2, 9, 4) == 9) {
        printf("Caso malo está bien, da %d\n", palindro_par(arreglo1, 11, 4));
        printf("Caso bueno está bien, da %d\n", palindro_par(arreglo2, 9, 4));
    } else {
        printf("Está mal, da %d en el caso malo\n", palindro_par(arreglo1, 11, 4));
        printf("Da %d en el caso bueno\n", palindro_par(arreglo2, 9, 4));
    }
    
}