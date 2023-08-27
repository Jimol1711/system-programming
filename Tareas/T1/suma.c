#include <stdio.h>

#include "suma.h"

Bcd sumaBcd(Bcd x, Bcd y) {
  Bcd ValorFinal = 0;
  Bcd acarreo = 0;
  // Se crea una máscara que corresponde al binario 0b1111 (15) para trabajar de a 4 bits.
  Bcd mascara4bits = 15;
  for(int i = 0; i<64; i+=4){
    Bcd mascaradigito = mascara4bits << i;
    Bcd digitox = (x & mascaradigito) >> i; // Se obtienen los dígitos
    Bcd digitoy = (y & mascaradigito) >> i;
    // Se suman los dígitos
    Bcd sum = digitox + digitoy + acarreo;
    if (sum >= 10) {
      acarreo = 1;
      sum -= 10;
    }
    else {
      acarreo = 0;
    }
    // Se agrega este condicional para el caso en que haya overflow
    if (i >= 60 && acarreo == 1)
      // Aquí hago un casteo para que no haya conflicto con el tipo del valor máximo
      ValorFinal = (Bcd)0xffffffffffffffff;
    else
      ValorFinal += (sum << i);  
  }
  return ValorFinal;
}

