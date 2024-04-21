// Autor: Leandro Luque (Fatec Mogi das Cruzes)

// Durante as férias, João Pedro gosta de aproveitar o tempo brincando com os amigos do prédio
// onde mora. Uma de suas brincadeiras preferidas é o “Peão Abre-Fecha Porta”. A brincadeira
// começa com a escolha de um dos participantes, o peão. Em seguida, os outros participantes
// definem um número e o peão deve passar por todos os andares do prédio que sejam múltiplos
// desse número para inverter o estado da porta do apartamento localizado no andar – ou seja,
// se a porta estiver aberta, ele a fechará; se estiver fechada, ele a abrirá. As portas estão
// inicialmente todas fechadas e existe apenas um apartamento por andar. A brincadeira segue
// com os participantes definindo novos números e o peão abrindo/fechando as portas dos
// andares múltiplos desses números. Quando o grupo desejar, o peão estiver muito cansado, ou
// algum morador reclamar, cada participante da brincadeira, com exceção do peão, é
// questionado sobre o estado das portas do prédio em cada andar (na ordem do mais baixo para
// o mais alto). Aquele que acerta, ganha um doce e fica livre de ser peão durante todo o dia.
// Como João Pedro adora doce e é um pouco preguiçoso, há tempos ele vem procurando por
// alguma forma de sempre ganhar a brincadeira. Para isso, ele pediu para o seu pai, um
// especialista em Informática, para desenvolver um programa que, dados os números que serão
// especificados pelos participantes, determina o estado final das portas dos andares.

// participantes
// escolhe um deles
// defini um numero
// o pear passar em todos andares multipos deste numero escolhido
// e inverte o estado deste andar, se aberto fecha, se fechado abre
// e isso se repte N vezes
// verifica se ainda quer continuar
// e imprimi o resultado final
#include <stdio.h>

#define MAX_TAM 100
#define TRUE 1
#define FALSE 0

int main()
{
  char predio[MAX_TAM];
  int c, A, N, x, numero;

  while (TRUE)
  {
    scanf("%d %d", &A, &N);
    if (A == 0 && N == 0)
      break;
    // A = quantidade de andares que via brincar = 10
    // N = quantidade de vezes que vai brincar = 5
    for (c = 0; c < A; c++)
      predio[c] = FALSE;

    for (c = 0; c < N; c++)
    {
      scanf("%d", &numero);
      for (x = numero - 1; x < A; x += numero)
        predio[x] = !predio[x];
    }

    for (c = 0; c < A; c++)
      printf("%c", predio[c] ? 'O' : 'C');
    printf("\n");
  }
  return 0;
}
