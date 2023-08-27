#include <stdio.h>

unsigned int repBits(unsigned int x, int i, int k, unsigned int val){
    unsigned int mascaraGuardar = -1 << i;
    mascaraGuardar = - mascaraGuardar;
    unsigned int mascara0 = -1 << (i+k);
    unsigned int mascara1 = val << i;
    unsigned int x_guardado = x & mascaraGuardar;
    x = x & mascara0;
    x = x | mascara1;
    return x | x_guardado;
}

void printBinary (unsigned int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    
}

int main(){
    unsigned int n = 0b110010111;
    printf("%d", repBits(n, 4, 2, 0b111));
    printf("\n");
    unsigned int n2 = 0b1101;
    printf("%d", repBits(n2, 4, 3, 0b111));
    printf("\n");
    return 0;
}