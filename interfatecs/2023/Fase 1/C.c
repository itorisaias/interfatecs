// #include <stdio.h>
// #include <string.h>

// #define MAX_N 26

// int main()
// {
//   int N;
//   char formato[11];
//   scanf("%d %10s", &N, formato);

//   char primeiroCaractere = strcmp(formato, "maiusculas") == 0 ? 'A' : 'a';
//   char saida[1000] = "", caracteres[MAX_N + 1] = "", preenchimento[MAX_N] = "";

//   memset(preenchimento, '.', MAX_N - 1);

//   for (int i = 0; i < N; i++)
//   {
//     strcat(saida, &preenchimento[i]);
//     for (int j = 0; j <= i; j++)
//       caracteres[j] = primeiroCaractere + j;
//     caracteres[i + 1] = '\0';
//     strcat(saida, caracteres);
//     strcat(saida, "\n");
//   }

//   printf("%s", saida);
//   return 0;
// }

#include <stdio.h>
#include <string.h>
#include <string.h>

#define ALFABETO "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define MAIUSCULAS "maiusculas"

void imprimir_linha(int n, int letras_maisculas)
{
  char linha[27];
  memset(linha, '.', 26 - n);
  strncpy(linha + (26 - n), ALFABETO, n);
  if (!letras_maisculas)
    for (int i = 0; i < n; i++)
      linha[i + (26 - n)] += 32;
  linha[26] = '\0';
  printf("%s\n", linha);
}

void imprimir_piramide(int n, int letras_maisculas)
{
  for (int i = 1; i <= n; i++)
    imprimir_linha(i, letras_maisculas);
}

int main()
{
  int tamanho;
  char formato_de_letra_desejado[11];
  scanf("%d %10s", &tamanho, formato_de_letra_desejado);
  imprimir_piramide(tamanho, strcmp(formato_de_letra_desejado, MAIUSCULAS) == 0);
  return 0;
}
