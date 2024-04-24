// beecrowd | 1009
// Salário com Bônus
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Faça um programa que leia o nome de um vendedor, o seu salário fixo e o total de vendas efetuadas por ele no mês (em dinheiro). Sabendo que este vendedor ganha 15% de comissão sobre suas vendas efetuadas, informar o total a receber no final do mês, com duas casas decimais.

// Entrada
// O arquivo de entrada contém um texto (primeiro nome do vendedor) e 2 valores de dupla precisão (double) com duas casas decimais, representando o salário fixo do vendedor e montante total das vendas efetuadas por este vendedor, respectivamente.

// Saída
// Imprima o total que o funcionário deverá receber, conforme exemplo fornecido.
#include <stdio.h>
#define COMISSAO 15

int main() {
  char nome[10];
  double salario, total_vendas, total_receber;
  fgets(nome, sizeof(nome), stdin);
  scanf("%lf", &salario);
  scanf("%lf", &total_vendas);
  total_receber = salario + (total_vendas * 0.15);
  printf("TOTAL = R$ %.2f\n", total_receber);
  return 0;
}
