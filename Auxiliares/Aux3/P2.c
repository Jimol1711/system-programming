#include <stdio.h>
#include "string.h"

int palindromo(char* s){
    char *p = s + strlen(s) - 1;
    while(s < p){
        if(*s != *p)
            return 0;
        s++;
        p--;
    };
};

void main(int argc, char *argv[]){
    char test[] = "somos";
    char test2[] = "hola";
    int res1 = palindromo(test);
    int res2 = palindromo(test2);
    printf("%s\n",test);
    printf("%s\n",test2);
};

