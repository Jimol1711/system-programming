#include <stdio.h>

#include "suma-dec.h"

Decimal sumaDecimal(Decimal x, Decimal y) {
  Decimal ValorFinal = 0;
  Decimal acarreo = 0;
  // Se crea una máscara que corresponde al binario 0b1111 (15) para trabajar de a 4 bits.
  Decimal mascara4bits = 15;
  for(int i = 0; i<64; i+=4){
    Decimal mascaradigito = mascara4bits << i;
    Decimal digitox = (x & mascaradigito) >> i; // Se obtienen los dígitos
    Decimal digitoy = (y & mascaradigito) >> i;
    // Se suman los dígitos
    Decimal sum = digitox + digitoy + acarreo;
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
      ValorFinal = (Decimal)0xffffffffffffffff;
    else
      ValorFinal += (sum << i);  
  }
  return ValorFinal;
}