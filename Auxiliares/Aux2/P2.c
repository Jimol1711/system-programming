#include "stdio.h"

int posicionBits(int x, int p, int n){
    int mascara = -1 << n;
    mascara = -mascara;
    for (int i=0; i<sizeof(int)*8-n; i++){
        if ((x & mascara) == p)
            return i;
        x = x>>1;
    }
    return -1;
}

int main(){
    unsigned int n = 0b110010111;
    printf("%d", posicionBits(n, 0b01, 2));
    printf("\n");
    unsigned int n2 = 0b1101;
    printf("%d", posicionBits(n2, 0b111, 3));
    printf("\n");
    return 0;
}