#include <stddef.h>

#include "prev.h"

void asignarPrev(Nodo *t, Nodo **pprev) {
  if (t == NULL) {
      return;
  }
  Nodo *prev = *pprev;
  if (t->izq != NULL)
    asignarPrev(t->izq, pprev);
}
