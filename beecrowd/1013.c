// // beecrowd | 1013
// O Maior
// Adaptado por Neilor Tonin, beecrowd  Brasil

// Timelimit: 1
// Faça um programa que leia três valores e apresente o maior dos três valores lidos seguido da mensagem “eh o maior”. Utilize a fórmula:

// Obs.: a fórmula apenas calcula o maior entre os dois primeiros (a e b). Um segundo passo, portanto é necessário para chegar no resultado esperado.

// Entrada
// O arquivo de entrada contém três valores inteiros.

// Saída
// Imprima o maior dos três valores seguido por um espaço e a mensagem "eh o maior".

#include <stdio.h>
#include <stdlib.h>
int maior(int A, int B) {
  return (A + B + abs(A - B)) / 2;
}
int main() {
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);
  int maiorAB = (A + B + abs(A-B)) / 2;
  int maior = (maiorAB + C + abs(maiorAB - C)) / 2;
  printf("%d eh o maior\n", maior);
}
