// beecrowd | 1021
// Notas e Moedas
// Por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Leia um valor de ponto flutuante com duas casas decimais. Este valor representa um valor monetário. A seguir, calcule o menor número de notas e moedas possíveis no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10, 0.05 e 0.01. A seguir mostre a relação de notas necessárias.

// Entrada
// O arquivo de entrada contém um valor de ponto flutuante N (0 ≤ N ≤ 1000000.00).

// Saída
// Imprima a quantidade mínima de notas e moedas necessárias para trocar o valor inicial, conforme exemplo fornecido.

// Obs: Utilize ponto (.) para separar a parte decimal.
#include <stdio.h>

#define NOTA_100 100
#define NOTA_50 50
#define NOTA_20 20
#define NOTA_10 10
#define NOTA_5 5
#define NOTA_2 2
#define MOEDA_100 100
#define MOEDA_050 50
#define MOEDA_025 25
#define MOEDA_010 10
#define MOEDA_005 5
#define MOEDA_001 1

int main()
{
  float valor;
  scanf("%f", &valor);

  float total_centavos = valor * 100;
  int notas_100, notas_50, notas_20, notas_10, notas_5, notas_2;
  int moedas_1, moedas_050, moedas_025, moedas_010, moedas_005, moedas_001;

  notas_100 = total_centavos / (NOTA_100 * 100);
  total_centavos -= notas_100 * (NOTA_100 * 100);
  notas_50 = total_centavos / (NOTA_50 * 100);
  total_centavos -= notas_50 * (NOTA_50 * 100);
  notas_20 = total_centavos / (NOTA_20 * 100);
  total_centavos -= notas_20 * (NOTA_20 * 100);
  notas_10 = total_centavos / (NOTA_10 * 100);
  total_centavos -= notas_10 * (NOTA_10 * 100);
  notas_5 = total_centavos / (NOTA_5 * 100);
  total_centavos -= notas_5 * (NOTA_5 * 100);
  notas_2 = total_centavos / (NOTA_2 * 100);
  total_centavos -= notas_2 * (NOTA_2 * 100);

  moedas_1 = total_centavos / MOEDA_100;
  total_centavos -= moedas_1 * MOEDA_100;
  moedas_050 = total_centavos / MOEDA_050;
  total_centavos -= moedas_050 * MOEDA_050;
  moedas_025 = total_centavos / MOEDA_025;
  total_centavos -= moedas_025 * MOEDA_025;
  moedas_010 = total_centavos / MOEDA_010;
  total_centavos -= moedas_010 * MOEDA_010;
  moedas_005 = total_centavos / MOEDA_005;
  total_centavos -= moedas_005 * MOEDA_005;
  moedas_001 = total_centavos / MOEDA_001;

  printf("NOTAS:\n");
  printf("%d nota(s) de R$ 100.00\n", notas_100);
  printf("%d nota(s) de R$ 50.00\n", notas_50);
  printf("%d nota(s) de R$ 20.00\n", notas_20);
  printf("%d nota(s) de R$ 10.00\n", notas_10);
  printf("%d nota(s) de R$ 5.00\n", notas_5);
  printf("%d nota(s) de R$ 2.00\n", notas_2);
  printf("MOEDAS:\n");
  printf("%d moeda(s) de R$ 1.00\n", moedas_1);
  printf("%d moeda(s) de R$ 0.50\n", moedas_050);
  printf("%d moeda(s) de R$ 0.25\n", moedas_025);
  printf("%d moeda(s) de R$ 0.10\n", moedas_010);
  printf("%d moeda(s) de R$ 0.05\n", moedas_005);
  printf("%d moeda(s) de R$ 0.01\n", moedas_001);

  return 0;
}

// #include <stdio.h>

// int main()
// {
//   double valor;
//   scanf("%lf", &valor);

//   int notas[6] = {100, 50, 20, 10, 5, 2};
//   int moedas[6] = {100, 50, 25, 10, 5, 1}; // Valores das moedas em centavos
//   float total_centavos = valor * 100;      // Convertendo o valor para centavos e arredondando

//   printf("NOTAS:\n");
//   for (int i = 0; i < 6; i++)
//   {
//     int qtd_notas = total_centavos / (notas[i] * 100);
//     printf("%d nota(s) de R$ %.2f\n", qtd_notas, notas[i] * 1.0);
//     total_centavos -= qtd_notas * (notas[i] * 100);
//   }

//   printf("MOEDAS:\n");
//   for (int i = 0; i < 6; i++)
//   {
//     int qtd_moedas = total_centavos / moedas[i];
//     printf("%d moeda(s) de R$ %.2f\n", qtd_moedas, moedas[i] / 100.0);
//     total_centavos -= qtd_moedas * moedas[i];
//   }

//   return 0;
// }

// segredo é aumento o valor para centavos pois fica mais fácil trabalhar
// essa tive que ler o forum
