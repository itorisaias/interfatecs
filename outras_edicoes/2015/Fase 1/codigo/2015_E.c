#include <stdio.h>
void processarMatrizEsparsa(int n)
{
  int matriz[n][n], qtdZero = 0, qtdTotalPosicao = n * n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      matriz[i][j] = 0;
  for (int i = 0; i < n; i++)
    matriz[i][i] = 2;
  for (int i = 0; i < n - 1; i++)
  {
    matriz[i][i + 1] = -1;
    matriz[i + 1][i] = -1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (matriz[i][j] == 0)
        qtdZero++;
  if (qtdZero > qtdTotalPosicao / 2)
    printf("%c %d\n", 'S', qtdZero);
  else
    printf("%c %d\n", 'N', qtdZero);
}

void processarMatriz(int q)
{
  int n;
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &n);
    processarMatrizEsparsa(n);
  }
}

int main()
{
  int q;
  scanf("%d", &q);
  processarMatriz(q);
  return 0;
}
