#include <stdio.h>

typedef enum fruta { manzana, pera, guinda, durazno, damasco } Fruta;

char *nombre_fruta[ ]= { "manzana", "pera", "guinda", "durazno", "damasco" };

typedef int Conjunto;

Conjunto singleton(Fruta f) {
  return 1<<f;
}

Conjunto Union(Conjunto r, Conjunto s) {
  return r | s;
}

Conjunto agregar(Fruta f, Conjunto s) {
  return Union(s, singleton(f));
}

int pertenece(Conjunto s, Fruta f) {
  return s & singleton(f);
}

Conjunto complemento(Conjunto s) {
  return ~s;
}
 
void mostrar(Conjunto s) {
  Fruta f; 
  for (f= manzana; f<= damasco; f++) {
    char *name;
    if (pertenece(s, f))
      printf("%s ", nombre_fruta[f]);
  }
  printf("\n");
}

int main() {
  Conjunto s1= agregar(manzana, agregar(guinda, singleton(damasco)));
  Conjunto s2= complemento(s1);

  mostrar(s1);
  mostrar(s2);
}
