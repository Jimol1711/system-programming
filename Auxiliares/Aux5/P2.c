#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int x;
    struct nodo *izq, *der;
} Nodo;

int reemplazarNodoK(Nodo **pa, int k, Nodo *b) {
    Nodo *a = *pa;
    int cnt_left = reemplazarNodoK(&a->izq, k, b);
     if (cnt_left == k) {
        return k;
     }
     else if (cnt_left == k-1) {
        *pa = b;
        return k;
     }
     int cnt_right = reemplazarNodo(&a->der, k-cnt_left-1, b);
     return cnt_left+1+cnt_right;
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
    
    Nodo *nuevo_arbol = createNodo(4, NULL, NULL);

    printArbol(arbol);
    printf("\n");
    reemplazarNodoK(&arbol, 3, nuevo_arbol);
    printf("\n");
    printArbol(arbol);
    printf("\n");

    return 0;
}