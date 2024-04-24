// beecrowd | 1017
// Gasto de Combustível
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Joaozinho quer calcular e mostrar a quantidade de litros de combustível gastos em uma viagem, ao utilizar um automóvel que faz 12 KM/L. Para isso, ele gostaria que você o auxiliasse através de um simples programa. Para efetuar o cálculo, deve-se fornecer o tempo gasto na viagem (em horas) e a velocidade média durante a mesma (em km/h). Assim, pode-se obter distância percorrida e, em seguida, calcular quantos litros seriam necessários. Mostre o valor com 3 casas decimais após o ponto.

// Entrada
// O arquivo de entrada contém dois inteiros. O primeiro é o tempo gasto na viagem (em horas) e o segundo é a velocidade média durante a mesma (em km/h).

// Saída
// Imprima a quantidade de litros necessária para realizar a viagem, com três dígitos após o ponto decimal
#include <stdio.h>
#define CONSUMO_VEICULO 12

int main() {
  int tempo_gasto_em_horas, velocidade_media_km_h;
  float litros_necessarios, total_km_andados;
  scanf("%d", &tempo_gasto_em_horas);
  scanf("%d", &velocidade_media_km_h);
  total_km_andados = tempo_gasto_em_horas * velocidade_media_km_h;
  litros_necessarios = total_km_andados / CONSUMO_VEICULO;
  printf("%.3f\n", litros_necessarios);
  return 0;
}
