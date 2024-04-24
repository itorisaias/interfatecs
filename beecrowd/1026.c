#include <stdio.h>

void printBinary(unsigned int num)
{
  for (int i = 31; i >= 0; i--)
  {
    printf("%d", (num >> i) & 1);
    if (i % 8 == 0)
      printf(" ");
  }
}

int main()
{
  // unsigned int num1, num2;

  // // Enquanto houver entrada
  // while (scanf("%u %u", &num1, &num2) != EOF) {
  //     unsigned int soma = 0; // Inicializa a soma como 0
  //     unsigned int carry = 0; // Inicializa o carry como 0

  //     // Loop pelos bits
  //     for (int i = 0; i < 32; i++) {
  //         unsigned int bit1 = (num1 >> i) & 1; // Pega o i-ésimo bit de num1
  //         unsigned int bit2 = (num2 >> i) & 1; // Pega o i-ésimo bit de num2

  //         // Soma os bits com o carry
  //         unsigned int soma_bit = bit1 ^ bit2 ^ carry;

  //         // Atualiza o carry
  //         carry = (bit1 & bit2) | ((bit1 | bit2) & carry);

  //         // Define o i-ésimo bit na soma
  //         soma |= (soma_bit << i);
  //     }

  //     // Imprime a soma
  //     printf("%u\n", soma);
  // }

  // 4 = 00000000 00000000 00000000 00000100
  // 6 = 00000000 00000000 00000000 00000110
  // ----------------------------------------
  // 2  = 00000000 00000000 00000000 00000010
  unsigned int numero = 4;
  printf("%032u\n", numero);

  return 0;
}
