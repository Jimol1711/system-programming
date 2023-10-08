#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *nom_dic = argv[1];

    FILE *arch = fopen(nom_dic, "r");
    fseek(arch, 0, SEEK_END);
    int size = ftell(arch);
    printf("El archivo es de %d bytes\n", size);

}