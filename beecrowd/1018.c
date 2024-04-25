#include <stdio.h>

#define NOTA_100 10000
#define NOTA_50 5000
#define NOTA_20 2000
#define NOTA_10 1000
#define NOTA_5 500
#define NOTA_2 200
#define NOTA_1 100

int main()
{
  int valor;
  scanf("%d", &valor);

  float total_centavos = valor * 100;
  int notas_100, notas_50, notas_20, notas_10, notas_5, notas_2, notas_1;

  notas_100 = total_centavos / NOTA_100;
  total_centavos -= notas_100 * NOTA_100;
  notas_50 = total_centavos / NOTA_50;
  total_centavos -= notas_50 * NOTA_50;
  notas_20 = total_centavos / NOTA_20;
  total_centavos -= notas_20 * NOTA_20;
  notas_10 = total_centavos / NOTA_10;
  total_centavos -= notas_10 * NOTA_10;
  notas_5 = total_centavos / NOTA_5;
  total_centavos -= notas_5 * NOTA_5;
  notas_2 = total_centavos / NOTA_2;
  total_centavos -= notas_2 * NOTA_2;
  notas_1 = total_centavos / NOTA_1;
  total_centavos -= notas_1 * NOTA_1;

  printf("%d\n", valor);
  printf("%d nota(s) de R$ 100,00\n", notas_100);
  printf("%d nota(s) de R$ 50,00\n", notas_50);
  printf("%d nota(s) de R$ 20,00\n", notas_20);
  printf("%d nota(s) de R$ 10,00\n", notas_10);
  printf("%d nota(s) de R$ 5,00\n", notas_5);
  printf("%d nota(s) de R$ 2,00\n", notas_2);
  printf("%d nota(s) de R$ 1,00\n", notas_1);

  return 0;
}
