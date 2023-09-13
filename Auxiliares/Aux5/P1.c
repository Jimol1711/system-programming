#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int x;
    struct nodo *izq, *der;
} Nodo;

void podar(Nodo **pa, int y) {
    Nodo *a = *pa;
    if (a == NULL) {
        return;
    }
    if (a->x <= y) {
        podar(&a->der, y);
    }
    else {
        podar(&a->izq, y);
        *pa = a->izq;
    }
}

// Funciones mágicas crea nodos
Nodo *createNodo(int x, Nodo *izq, Nodo *der) {
    Nodo *a = (Nodo*)malloc(sizeof(Nodo));
    a->x = x;
    a->izq = izq;
    a->der = der;
    return a;
}

void printArbol(Nodo *a) {
    if (a == NULL) return;
    printArbol(a->izq);
    printf("%i", a->x);
    printArbol(a->der);
}

int main() {
    Nodo *arbol =
        createNodo(4,
            createNodo(2,
                createNodo(1, NULL, NULL),
                createNodo(3, NULL, NULL)),
            createNodo(6,
                createNodo(5, NULL, NULL),
                NULL));

    printArbol(arbol);
    printf("\n");
    podar(&arbol, 0);
    printf("\n");
    printArbol(arbol);
    printf("\n");

    return 0;
}