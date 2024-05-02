// beecrowd | 1042
// Sort Simples
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Leia 3 valores inteiros e ordene-os em ordem crescente. No final, mostre os valores em ordem crescente, uma linha em branco e em seguida, os valores na sequência como foram lidos.

// Entrada
// A entrada contem três números inteiros.

// Saída
// Imprima a saída conforme foi especificado.

#include <stdio.h>
int main()
{
  int vet[3], aux[3];

  scanf("%d %d %d", &vet[0], &vet[1], &vet[2]);

  for (int i = 0; i < 3; i++)
    aux[i] = vet[i];

  for (int i = 0; i < 3 - 1; i++)
  {
    for (int j = 0; j < 3 - i - 1; j++)
    {
      if (aux[j] > aux[j + 1])
      {
        int temp = aux[j];
        aux[j] = aux[j + 1];
        aux[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < 3; i++)
    printf("%d\n", aux[i]);

  printf("\n");

  for (int i = 0; i < 3; i++)
    printf("%d\n", vet[i]);

  return 0;
}
