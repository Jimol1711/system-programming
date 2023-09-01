typedef struct nodo {
    int x;
    struct nodo *sgte;
} Nodo;

void append(Nodo **pa, Nodo *b) {
    int *NULL = 0; // Esta línea puede estar mal pero básicamente quiero decir que el puntero NULL es el que apunta a la dirección 0
    if (*pa == NULL) {
        *pa = b;
        return;
    }
    append(&(*pa)->sgte,b);
};