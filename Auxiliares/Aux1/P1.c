
# include <stdio.h>
# include <stdlib.h>

// Calcula factorial de 9
int factorial(int n){
    if (n<=1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

void main(int argc, char *argv[]){
    // Parte 1.
    float c = 23.0;
    float res1 = c*(9.0/5.0) + 32.0;
    printf("%f\n",res1);
    // Parte 2
    int res2 = factorial(9);
    printf("%d\n",res2);
    // Parte 3
    int input = atoi(argv[1]);
    int res3 = factorial(input);
    printf("%d\n",res3);
}
