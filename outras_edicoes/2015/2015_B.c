// Museu
// Arquivo fonte: museu.{c | cpp | java}
// Autor: Emanuel Mineda Carneiro (FATEC-SJC)  Um  museu  recebeu  um  conjunto  de  obras  de  arte  formadas  por  azulejos  quadrados.
// Todos os azulejos possuem o mesmo tamanho e são totalmente coloridos nas cores branca ou
// preta. O diretor do museu decidiu classificar as obras pela quantidade de figuras contida em
// cada  uma.  Uma  figura  é  composta  por  azulejos  vizinhos  de  cor  preta.  Dois  azulejos  são
// considerados  vizinhos  se  um  lado  de  um  se  encontra  totalmente  unido  a  um  lado  do  outro.
// Desta  forma,  um  azulejo  pode  possuir,  no  máximo,  quatro  vizinhos:  um  acima,  um  abaixo,
// um à direita e outro à esquerda. A Tabela 1 apresenta um exemplo de obra de arte formada por 10 colunas de azulejos,
// com  altura  de  8  azulejos.  Esta  obra  de  arte  apresenta  4  figuras,  compostas  por  azulejos
// vizinhos de cor preta
// Você  foi  contratado  para  desenvolver  um  programa  capaz  de  contar  a  quantidade  de
// figuras contidas em cada obra de arte. Entrada
// A entrada é composta por vários casos de teste. A primeira linha de cada caso de teste
// contém a quantidade de azulejos na horizontal H (0 < H < 15) e na vertical V (0 < V < 15). As
// linhas  seguintes  contém  a  cor  dos  azulejos  (0  para  branco  e  1  para  preto),  separados  por  um
// espaço em branco. Os casos de teste terminam com o final do arquivo (EOF).
// Saída
// Para cada caso de teste, deve ser impressa a quantidade de figuras encontradas na obra.
// Cada linha deve possuir o resultado de um único caso de teste
// Exemplos

// Entrada:
// 6 5
// 0 0 0 0 1 1
// 0 1 0 1 0 0
// 0 1 1 0 1 0
// 0 0 1 1 1 0
// 0 0 0 0 0 0
// 7 3
// 1 0 0 1 1 1 1
// 1 1 0 0 0 1 0
// 0 1 1 0 0 1 0

#include <stdio.h>

#define MAX_VALUE 15

int mat[MAX_VALUE][MAX_VALUE];

void verificar(int count_linha, int count_coluna, int linha, int coluna)
{
  if (linha < 0 || linha >= count_linha || coluna < 0 || coluna >= count_coluna || mat[linha][coluna] != 1)
  {
    return;
  }

  mat[linha][coluna] = 0;

  verificar(count_linha, count_coluna, linha, coluna - 1); //cima
  verificar(count_linha, count_coluna, linha, coluna + 1); //baixo
  verificar(count_linha, count_coluna, linha - 1, coluna); //esquerda
  verificar(count_linha, count_coluna, linha + 1, coluna); //direita
}

void imprimirMatriz(int h, int v)
{
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < v; j++)
    {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int h, v, imgCount = 0;
  scanf("%d %d", &h, &v);

  for (int i = 0; i < h; i++)
    for (int j = 0; j < v; j++)
      scanf("%d", &mat[i][j]);

  for (int linha = 0; linha < h; linha++)
    for (int coluna = 0; coluna < v; coluna++)
      if (mat[linha][coluna] == 1)
      {
        verificar(h, v, linha, coluna);
        imprimirMatriz(h, v);
        printf("\n\n");
        imgCount++;
      }

  printf("R: %d", imgCount);

  return 0;
}
