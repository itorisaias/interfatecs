// beecrowd | 1014
// Consumo
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Calcule o consumo médio de um automóvel sendo fornecidos a distância total percorrida (em Km) e o total de combustível gasto (em litros).

// Entrada
// O arquivo de entrada contém dois valores: um valor inteiro X representando a distância total percorrida (em Km), e um valor real Y representando o total de combustível gasto, com um dígito após o ponto decimal.

// Saída
// Apresente o valor que representa o consumo médio do automóvel com 3 casas após a vírgula, seguido da mensagem "km/l".

#include <stdio.h>
int main() {
  int distancia_total_percorrida;
  float total_combustivel_gasto, consumo_medio;

  scanf("%d", &distancia_total_percorrida);
  scanf("%f", &total_combustivel_gasto);

  consumo_medio = distancia_total_percorrida / total_combustivel_gasto;

  printf("%.3f km/l\n", consumo_medio);

  return 0;
}
