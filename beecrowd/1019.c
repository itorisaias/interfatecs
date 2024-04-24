// beecrowd | 1019
// Conversão de Tempo
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Leia um valor inteiro, que é o tempo de duração em segundos de um determinado evento em uma fábrica, e informe-o expresso no formato horas:minutos:segundos.

// Entrada
// O arquivo de entrada contém um valor inteiro N.

// Saída
// Imprima o tempo lido no arquivo de entrada (segundos), convertido para horas:minutos:segundos, conforme exemplo fornecido.

#include <stdio.h>
int main() {
  int tempo_em_segundos;
  int horas, minutos, segundos;
  scanf("%d", &tempo_em_segundos);

  horas = tempo_em_segundos / 60 / 60;
  minutos = (tempo_em_segundos - (horas * 60 * 60)) / 60;
  segundos = tempo_em_segundos - ((horas * (60 * 60)) + (minutos * 60));

  printf("%d:%d:%d\n", horas, minutos, segundos);
  return 0;
}
// 140153
