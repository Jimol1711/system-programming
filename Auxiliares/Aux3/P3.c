#include <stdio.h>
#include "string.h"

void reverse(char* s){
    char *p = s + strlen(s) -1;
    while (s < p) {
        char tmp = s;
        *s = *p;
        *p = tmp;
        s++;
        p--;
    }
};

void main(int argc, char *argv[]){
    char test[] = "djahs";
    char test2[] = "reconoce";
    reverse(test);
    reverse(test2);
    printf("%s\n",test);
    printf("%s\n",test2);
};