// beecrowd | 1020
// Idade em Dias
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Leia um valor inteiro correspondente à idade de uma pessoa em dias e informe-a em anos, meses e dias

// Obs.: apenas para facilitar o cálculo, considere todo ano com 365 dias e todo mês com 30 dias. Nos casos de teste nunca haverá uma situação que permite 12 meses e alguns dias, como 360, 363 ou 364. Este é apenas um exercício com objetivo de testar raciocínio matemático simples.

// Entrada
// O arquivo de entrada contém um valor inteiro.

// Saída
// Imprima a saída conforme exemplo fornecido.
#define ANO 365
#define MES 30

#include <stdio.h>
int main() {
  int idade_em_dias, anos, meses, dias;
  scanf("%d", &idade_em_dias);

  anos = idade_em_dias / ANO;
  meses = (idade_em_dias - (anos * 365)) / MES;
  dias = idade_em_dias - ((anos * ANO) + (meses * MES));

  printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
  return 0;
}
