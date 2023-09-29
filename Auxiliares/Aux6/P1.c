#include <stdio.h>
#include <string.h>

void modificar(char *nom_dic, char *palabra, char *def, int n_lin, int ancho) {
    char buff[ancho + 1];
    FILE *f = fopen(nom_dic, "r+");
    while(fread(buff, 1, ancho, f) > 0) {
        char *c = buff;
        while(*c != ':') {
            c++;
        }
        *c = '\0';
        if (strcmp(buff,palabra) == 0) {
            fseek(f, ancho+strlen(palabra)+1, SEEK_CUR);
            fputs(def, f);
            while(fgetc(f) != ':') {
                fseek(f, -1, SEEK_CUR);
                fputc(' ', f);
            }
        }
    }
    fclose(f);
};

void main() {
    //...
};