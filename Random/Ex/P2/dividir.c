#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "dividir.h"

void dividir(Nodo *nodo, Nodo **pimpares, Nodo **ppares) {
  *pimpares = NULL;
  *ppares = NULL;

  int index = 0;

  if (nodo == NULL) {
    return;
  }
  
  if (index % 2 == 0) {
    *pimpares = nodo->prox;
    index += 1;
    nodo += index;
  } else {
    *ppares = nodo->prox;
    index += 1;
    nodo += index;
  }

  dividir(nodo,pimpares,ppares);
}
