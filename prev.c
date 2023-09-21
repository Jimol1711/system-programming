#include <stddef.h>

#include "prev.h"

void asignarPrev(Nodo *t, Nodo **pprev) {
    if (t != NULL) {
        // Se recorre el subárbol izquierdo
        asignarPrev(t->izq, pprev);
        t->prev = *pprev; // El nodo previo es *pprev

        // Si el nodo previo no es NULL, actualizamos su nodo próximo
        if (*pprev != NULL) {
            (*pprev)->prox = t;
        }

        // El nodo actual se convierte en el nodo previo
        *pprev = t;
        
        // Se recorre el subárbol derecho
        asignarPrev(t->der, pprev);
        if (*pprev == t) {
            (*pprev)->prox = NULL; // Se asigna NULL al último nodo recorrido
        }
    }
}
