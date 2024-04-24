#include <stdio.h>
#include <math.h>

int main()
{
  double pi = 3.14159; // Usando M_PI da biblioteca math.h para obter o valor preciso de pi
  double base = 2.00;
  double raio, area;

  scanf("%lf", &raio);
  area = pi * pow(raio, 2.00);

  printf("A=%.4f\n", area);

  return 0;
}
