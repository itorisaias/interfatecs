#include <stdio.h>

int main()
{
  int dia, mes, colegas, diaColega, mesColega;
  int encontrado = 0; // 0 para falso, 1 para verdadeiro

  while (scanf("%d %d", &dia, &mes) == 2 && (dia != 0 || mes != 0))
  {
    encontrado = 0;
    scanf("%d", &colegas);

    for (int i = 0; i < colegas; i++)
    {
      scanf("%d %d", &diaColega, &mesColega);

      if (dia == diaColega && mes == mesColega)
      {
        encontrado = 1;
      }
    }
    printf("%c\n", (encontrado ? 'S' : 'N'));
  }

  return 0;
}
