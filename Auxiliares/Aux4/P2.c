#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char *info;
    struct nodo *sgte;
} Nodo;

typedef struct {
    Nodo *primero;
    Nodo *ultimo;
} Cola;

Cola *crearcola() {
    Cola *retcola = malloc(sizeof(Cola));
    retcola->primero = NULL;
    retcola->ultimo = NULL;
    return retcola;
};

void put(Cola* q, char *str);
char *get(Cola* p);
void freeCola(Cola *q);

int main () {
    Cola *q = crearCola();
    char a[] = "wena";
    put(q,a);
    char b[] = "qtal";
    put(q,b);

    printf("%s\n",)
};