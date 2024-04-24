// // beecrowd | 1030
// // A Lenda de Flavious Josephus
// // Por Neilor Tonin, URI  Brasil

// // Timelimit: 1
// // O problema de Josephus é assim conhecido por causa da lenda de Flavius Josephus, um historiador judeu que viveu no século 1. Segundo o relato de Josephus do cerco de Yodfat, ele e seus companheiros (40 soldados) foram presos em uma caverna, cuja saída foi bloqueada pelos romanos. Eles preferiram suicidar-se a serem capturados, e decidiram que iriam formar um círculo e começar a matar-se pulando de três em três. Josephus afirma que, por sorte ou talvez pela mão de Deus, ele permaneceu por último e preferiu entregar-se aos romanos a suicidar-se.

// // Entrada
// // Haverá NC (1 ≤ NC ≤ 30 ) casos de teste. Em cada caso de teste de entrada haverá um par de números inteiros positivos n (1 ≤ n ≤ 10000 ) e k (1 ≤ k ≤ 1000). O  número n representa a quantidade de pessoas no círculo, numeradas de 1 até n. O número k representa o tamanho do salto de um homem até o próximo homem que será morto.

// // Segue um exemplo com 5 homens e um salto = 2.

// // Neste exemplo o elemento que restará após as eliminações é 3.
// // Saída
// // Para cada caso de teste de entrada será apresentada uma linha de saída no seguinte formato: Case n: m tendo sempre um espaço antes do n e do m.

// #include <stdio.h>

// int jogadores_restantes(int circulo[], int quantidade_pessoas) {
//   int jogadores_vivo = 0;
//   for (int i = 0; i < quantidade_pessoas; i++)
//   {
//     if (circulo[i] == 1)
//       jogadores_vivo++;
//   }

//   return jogadores_vivo;
// }

// int ultimo_jogador(int circulo[], int quantidade_pessoas) {
//   for (int i = 0; i < quantidade_pessoas; i++)
//   {
//     if (circulo[i] == 1)
//       return i;
//   }

//   return -1;
// }

// void jogar(int caso) {
//   int quantidade_pessoas, salto;
//   scanf("%d %d", &quantidade_pessoas, &salto);
//   int circulo[quantidade_pessoas];
//   int indice = 0, ultimo = -1;

//   for (int i = 0; i < quantidade_pessoas; i++)
//     circulo[i] = 1;

//   while (1)
//   {
//     // logica quando vcs precisam retornar no elemento dando saltos
//     indice = (indice + salto) % quantidade_pessoas;

//     circulo[indice] = 0;

//     int quantidade = jogadores_restantes(circulo, quantidade_pessoas);
//     printf("Para rodada %d existe ainda %d vivos", caso, quantidade);
//     if (quantidade == 1)
//     {
//       ultimo = ultimo_jogador(circulo, quantidade_pessoas);
//       break;
//     }
//   }

//   printf("Case %d: %d\n", caso, ultimo);
// }

// int main() {
//   int qtd;
//   scanf("%d", &qtd);

//   for (int i = 1; i <= qtd; i++)
//   {
//     jogar(i);
//   }

//   return 0;
// }
#include <stdio.h>

// int josephus(int quantidade_pessoas, int salto)
// {
//   if (quantidade_pessoas == 1) // Caso base: se houver apenas uma pessoa, ela é a sobrevivente
//     return 1;
//   else
//     // O índice do sobrevivente na iteração anterior é (josephus(n - 1, k) + k - 1) % n + 1
//     return (josephus(quantidade_pessoas - 1, salto) + salto - 1) % quantidade_pessoas + 1;
//     // exemplo de 5 2
//     // ((5 - 1, 2) + 2 - 1) % 5 + 1 => ((4, 2) + 1) % 6
//     // ((4 - 1, 2) + 2 - 1) % 4 + 1 => ((3, 2) + 1) % 5
//     // ((3 - 1, 2) + 2 - 1) % 3 + 1 => ((2, 2) + 1) % 4
//     // ((2 - 1, 2) + 2 - 1) % 2 + 1 => ((1, 1) + 1) % 3
//     // ((1 - 1, 2) + 2 - 1) % 1 + 1 => ((0) + 1) % 2
// }

int josephus(int n, int k)
{
  int sobrevivente = 0; // Inicialmente, o sobrevivente é o primeiro elemento

  // Itera através de todos os elementos do círculo
  for (int i = 2; i <= n; i++)
  {
    sobrevivente = (sobrevivente + k) % i;
  }

  return sobrevivente + 1;
}

int main()
{
  int NC, qtd = 0; // Número de casos de teste
  scanf("%d", &NC);

  while (1)
  {
    int quantidade_pessoas, salto;
    scanf("%d %d", &quantidade_pessoas, &salto);

    int sobrevivente = josephus(quantidade_pessoas, salto);
    printf("Case %d: %d\n", qtd + 1, sobrevivente);
    qtd++;
    if (qtd == NC)
      break;
  }

  return 0;
}
