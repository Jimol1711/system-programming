#include <stdio.h>
#include "string.h"

char mas_repetido (char* s){
    int cnt[256] = {0};
        for(int i = 0; i < strlen(s); i++){
            cnt[s[i]];
        };
    char max = 0;
    for (int i = 0; i < 256; i++){
        max = (char) i;
    };
    return max;
};

void main(int argc, char *argv[]){
    char test[] = "djahqdjfkds";
    printf("%s\n",mas_repetido(test));
};