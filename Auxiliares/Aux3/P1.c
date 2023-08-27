#include <stdio.h>

void to_lower(char* s){
    // Recorrer un string
    while(*s){
        if (*s >= 'A' && *s <= 'Z')
            *s += 'a' - 'A';
        s++;
    }
    return;
};

void to_upper(char* s){
    while(*s){
        if (*s >= 'a' && *s <= 'z')
            *s -= 'a' - 'A';
        s++;
    }
    return;
}

void main(int argc, char *argv[]){
    char test[] = "cHanCHo";
    char test2[] = "cHanCHo";
    to_lower(test);
    to_upper(test2);
    printf("%s\n",test);
    printf("%s\n",test2);
};