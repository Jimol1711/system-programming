#include <stdio.h>

int bits1(unsigned int n){
    if (n == 0)
        return 0;
    if (n & 1)
        return 1 + bits1(n >> 1);
    return bits1(n >> 1);
};

int main(){
    unsigned int n = 15;
    printf("%d", bits1(n));
    printf("\n");
    unsigned int n2 = 0b1101;
    printf("%d", bits1(n2));
    printf("\n");
    return 0;
}