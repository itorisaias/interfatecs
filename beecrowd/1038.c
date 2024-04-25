// beecrowd | 1038
// Lanche
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Com base na tabela abaixo, escreva um programa que leia o código de um item e a quantidade deste item. A seguir, calcule e mostre o valor da conta a pagar.

// Entrada
// O arquivo de entrada contém dois valores inteiros correspondentes ao código e à quantidade de um item conforme tabela acima.

// Saída
// O arquivo de saída deve conter a mensagem "Total: R$ " seguido pelo valor a ser pago, com 2 casas após o ponto decimal.
#include <stdio.h>
struct Produto
{
  int codigo;
  char *especificacao;
  float preco;
};
int main() {
  struct Produto cardapio[] =
  {
    {1, "Cachorro Quente", 4.00},
    {2, "X-Salada", 4.50},
    {3, "X-Bacon", 5.00},
    {4, "Torrada simples", 2.00},
    {5, "Refrigerante", 1.50},
  };

  int codigo, quantidade;
  float total = 0;
  scanf("%d %d", &codigo, &quantidade);

  for (int i = 0; i < sizeof(cardapio) / sizeof(cardapio[0]); i++)
  {
    if (cardapio[i].codigo == codigo) {
      total += cardapio[i].preco * quantidade;
    }
  }

  printf("Total: R$ %.2f\n", total);
  return 0;
}
