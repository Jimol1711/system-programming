#include <stdio.h>

typedef unsigned long long Bcd;

Bcd verBcd(Bcd x){
    return x;
}

int main(){
    unsigned int n = 0x1023;
    printf("%d", verBcd(n));
    printf("\n");
    return 0;
}