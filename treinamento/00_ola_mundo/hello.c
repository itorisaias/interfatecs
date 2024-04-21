#include <stdio.h>

int main()
{
  char letra;
  int n;

  while (1) // while true
  {
    scanf("%c", &letra);
    scanf("%d", &n);

    printf("%c - %d", letra, n);
    printf("\n");

    if (n == 2)
    {
      break;
    }
  }

  return 0;
}
