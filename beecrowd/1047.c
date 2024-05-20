// beecrowd | 1047
// Tempo de Jogo com Minutos
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo. A seguir calcule a duração do jogo.

// Obs: O jogo tem duração mínima de um (1) minuto e duração máxima de 24 horas.

// Entrada
// Quatro números inteiros representando a hora de início e fim do jogo.

// Saída
// Mostre a seguinte mensagem: “O JOGO DUROU XXX HORA(S) E YYY MINUTO(S)” .

// Exemplo de Entrada	Exemplo de Saída
// 7 8 9 10

// O JOGO DUROU 2 HORA(S) E 2 MINUTO(S)

// 7 7 7 7

// O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)

// 7 10 8 9

// O JOGO DUROU 0 HORA(S) E 59 MINUTO(S)

#include <stdio.h>

int main()
{
  int hora_inicio, minuto_inicio, hora_fim, minuto_fim;
  int duracao_horas, duracao_minutos;

  scanf("%d %d %d %d", &hora_inicio, &minuto_inicio, &hora_fim, &minuto_fim);

  duracao_horas = hora_fim - hora_inicio;
  duracao_minutos = minuto_fim - minuto_inicio;

  if (duracao_minutos < 0)
  {
    duracao_minutos += 60;
    duracao_horas--;
  }

  if (duracao_horas <= 0)
    duracao_horas += 24;

  // Saída da duração do jogo
  printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_horas, duracao_minutos);

  return 0;
}
