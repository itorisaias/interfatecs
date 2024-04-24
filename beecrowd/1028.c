#include <stdio.h>

// Função para calcular o MDC (máximo divisor comum) entre dois números
// int mdc(int a, int b)
// {
//   if (b == 0)
//     return a;
//   return mdc(b, a % b);
// }

// 8 12
int mdc(int a, int b)
{
  while (b != 0)
  {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main()
{
  int N; // Número de casos de teste
  scanf("%d", &N);

  while (N--)
  {
    int F1, F2; // Quantidade de figurinhas de Ricardo e Vicente
    scanf("%d %d", &F1, &F2);

    // Calcula o MDC entre F1 e F2
    int tamanho_max_pilha = mdc(F1, F2);

    printf("%d\n", tamanho_max_pilha);
  }

  return 0;
}
