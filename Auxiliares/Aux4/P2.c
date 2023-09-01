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

void put(Cola* q, char *str) {
    Nodo *porEntrar = malloc(sizeof(Nodo));
    porEntrar->info = str;
    porEntrar->sgte = NULL;
    if (q->primero == NULL) {
        q->primero = porEntrar;
        q->ultimo = porEntrar;
        return;
    }
    Nodo *penultimo = q->ultimo;
    penultimo->sgte = porEntrar;
    q->ultimo = porEntrar;
};
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