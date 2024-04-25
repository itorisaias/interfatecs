// beecrowd | 1036
// Fórmula de Bhaskara
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de Bhaskara. Se não for possível calcular as raízes, mostre a mensagem correspondente “Impossivel calcular”, caso haja uma divisão por 0 ou raiz de numero negativo.

// Entrada
// Leia três valores de ponto flutuante (double) A, B e C.

// Saída
// Se não houver possibilidade de calcular as raízes, apresente a mensagem "Impossivel calcular". Caso contrário, imprima o resultado das raízes com 5 dígitos após o ponto, com uma mensagem correspondente conforme exemplo abaixo. Imprima sempre o final de linha após cada mensagem.
#include <stdio.h>
#include <math.h>
int main(){
  double A, B, C, delta, r1, r2;
  scanf("%lf %lf %lf", &A, &B, &C);

  // (-b±√(b²-4ac))/(2a)
  delta = (B*B) - (4*A*C);
  r1 = ((-B) + (sqrt(delta))) / (2*A);
  r2 = ((-B) - (sqrt(delta))) / (2*A);

  if (A <= 0 || B <= 0 || C <= 0 || delta <= 0) {
    printf("Impossivel calcular\n");
  } else {
    printf("R1 = %.5lf\n", r1);
    printf("R2 = %.5lf\n", r2);
  }
  return 0;
}
