// beecrowd | 1043
// Triângulo
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Leia 3 valores reais (A, B e C) e verifique se eles formam ou não um triângulo. Em caso positivo, calcule o perímetro do triângulo e apresente a mensagem:


// Perimetro = XX.X


// Em caso negativo, calcule a área do trapézio que tem A e B como base e C como altura, mostrando a mensagem


// Area = XX.X

// Entrada
// A entrada contém três valores reais.

// Saída
// O resultado deve ser apresentado com uma casa decimal.

#include <stdio.h>

int main() {
  double A, B, C, area, perimetro;
  scanf("%lf %lf %lf", &A, &B, &C);

  if (A + B > C && A + C > B && B + C > A) {
    // é triangulo
  } else {
    // não
  }

  return 0;
}
