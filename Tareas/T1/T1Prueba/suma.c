#include <stdio.h>

#include "suma.h"

Bcd sumaBcd(Bcd x, Bcd y) {
  // Programe aca la funcion pedida
  Bcd ValorFinal = 0;
  // Se crea una máscara que corresponde al binario 0b1111 (15) para trabajar de a 4 bits.
  Bcd mascara4bits = 15;
  for(int i = 0; i<64; i+=4){
    Bcd mascaradigito = mascara4bits << i;
    Bcd digitox = (x & mascaradigito) >> i; // Se obtienen los dígitos
    Bcd digitoy = (y & mascaradigito) >> i;
    // Se suman los dígitos
    Bcd sum = digitox + digitoy;
    Bcd sumadigitos;
    Bcd acarreo;
    if (sum < 10) {
      sumadigitos = sum;
      acarreo = 0;
    }
    else {
      sumadigitos = sum - 10;
      acarreo = 1;
    }
    if (i > 60 && acarreo == 1)
      ValorFinal = 0xffffffffffffffff;
    else
      ValorFinal += (sumadigitos << i) + (acarreo << (i+4));
  }
  return ValorFinal;
}

void main() {
  Bcd n1 = 0x89;
  Bcd n2 = 0x1;
  printf("%d", sumaBcd(n1,n2));
  printf("\n");
  return 0;
}
