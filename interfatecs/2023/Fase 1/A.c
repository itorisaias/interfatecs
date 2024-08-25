// Na tranquila Universidade de Blaittland, existe uma antiga biblioteca repleta de raridades, incluindo uma estante transbordando de livros de linguagens de programação. Todas as manhãs, esses livros são meticulosamente organizados em ordem alfabética da esquerda para a direita. Nenhum dos livros tem títulos que começam com a mesma letra. No entanto, os estudantes, sempre correndo em direção aos prazos das tarefas, escolhem livros para ler e os colocam de volta exatamente uma posição à esquerda de sua posição original, mantendo uma única semelhança de desordem na estante.
// Curiosamente, os estudantes de Análise de Sistemas e Desenvolvimento adotaram um hábito peculiar: se um livro foi lido por mais de cinco pessoas durante um dia, eles não o leem novamente. Essa regra não escrita, no entanto, nem sempre é respeitada pelos estudantes de Sistemas de Banco de Dados. Outra peculiaridade que foi observada é que ninguém nunca pega o livro localizado mais à esquerda para ler.
// No final do dia, Jeff, o bibliotecário, não só precisa calcular o número de vezes que os livros foram escolhidos para ler, mas também deseja determinar se é possível ter certeza de que algum estudante de Sistemas de Banco de Dados leu um livro.
// Entrada
// A primeira linha contém um único inteiro N (1 ≤ N ≤ 26), representando o número de livros na estante. A segunda linha contém uma sequência de N letras maiúsculas (de A a Z), representando a ordem final dos livros na estante.

// Saída
// Se for possível afirmar (além de qualquer dúvida) que um estudante de Sistemas de Banco de Dados leu um livro, imprima "Um estudante de Sistemas de Banco de Dados leu um livro". Caso contrário, imprima um único inteiro, representando o número de vezes que qualquer livro foi escolhido para ler. Lembre-se de incluir uma nova linha ao final da sua saída.

// #include <stdio.h>

// int main()
// {
//   int quantidade_livros, countMove = 0, the_same_book_move_5_times = 0;
//   scanf("%d", &quantidade_livros);

//   int book_ascii[quantidade_livros];
//   char book_sequence[quantidade_livros + 1];
//   scanf("%s", book_sequence);

//   for (int i = 0; i < quantidade_livros; i++) {
//     book_ascii[i] = (int)book_sequence[i];
//   }

//   // Case 1
//   // DFGHMNQRSVYZ - estado inicial da estante
//   // DFGMHNQRSVYZ -> M foi pego
//   // DFGMNHQRSVYZ -> N foi pego
//   // DFGNMHQRSVYZ -> N foi pego
//   // DFGNMHRQSVYZ -> R foi pego
//   // DFGNMHRQSYVZ -> Y foi pego
//   // DFGNMHRQSYVZ -> estado final da estante
//   // Então o livros foram movidos 5 vezes
//   // Case 2
//   // ABCDEFG - estado inicial da estante
//   // ABCDEGF -> G foi pego
//   // ABCDGEF -> G foi pego
//   // ABCGDEF -> G foi pego
//   // ABGCDEF -> G foi pego
//   // AGBCDEF -> G foi pego
//   // GABCDEF -> G foi pego
//   // fluxo continua até chegar no final
//   // GCBADEF - estado final da estante
//   // No caso 2 o G foi pego mais de 5 vezes então posso parar o loop e coloca que the_same_book_move_5_times=1
//   // Se o mesmo livro se moveu mais de 5 vezes eu preciso verificar antes se um mesmo livro se moveu mais de 5 vezes de sua posição inicial

//   for (int i = 0; i < quantidade_livros - 1; i++)
//   {
//     for (int j = 0; j < quantidade_livros - i - 1; j++)
//     {
//       if (book_ascii[j] > book_ascii[j + 1])
//       {
//         int temp = book_ascii[j];
//         book_ascii[j] = book_ascii[j + 1];
//         book_ascii[j + 1] = temp;
//         countMove++;
//       }
//     }
//   }

//   if (the_same_book_move_5_times == 1)
//     printf("Um estudante de Sistemas de Banco de Dados leu um livro");
//   else
//     printf("%d\n", countMove);

//   return 0;
// }

#include <stdio.h>
#define MAXIMO 26

int main()
{
  int quantidade_livros, countMove = 0, the_same_book_move_5_times = 0;
  scanf("%d", &quantidade_livros);

  int book_ascii[quantidade_livros];
  char book_sequence[quantidade_livros + 1];
  scanf("%s", book_sequence);

  int moves_from_initial_position[MAXIMO] = {0};

  for (int i = 0; i < quantidade_livros; i++)
    book_ascii[i] = (int)book_sequence[i];

  for (int i = 0; i < quantidade_livros - 1; i++)
  {
    for (int j = 0; j < quantidade_livros - i - 1; j++)
    {
      if (book_ascii[j] > book_ascii[j + 1])
      {
        int temp = book_ascii[j];
        book_ascii[j] = book_ascii[j + 1];
        book_ascii[j + 1] = temp;
        countMove++;
        moves_from_initial_position[temp - 'A']++; // Incrementa o contador de movimentos para o livro atual
      }
    }
  }

  for (int i = 0; i < MAXIMO; i++)
  {
    if (moves_from_initial_position[i] > 5)
    {
      the_same_book_move_5_times = 1;
      break;
    }
  }

  // Verifica se um estudante de Sistemas de Banco de Dados leu um livro
  if (the_same_book_move_5_times == 1)
  {
    printf("Um estudante de Sistemas de Banco de Dados leu um livro\n");
  }
  else
  {
    printf("%d\n", countMove);
  }

  return 0;
}

// ---

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//   int N;
//   scanf("%d", &N);

//   char bookOrder[N + 1];
//   scanf("%s", bookOrder);

//   char characters[N + 1];
//   strcpy(characters, bookOrder);
//   qsort(characters, N, sizeof(char), strcmp);

//   char bookSteps[N + 1];
//   strcpy(bookSteps, characters);

//   int numReads = 0;
//   for (int i = 0; i < N; i++)
//   {
//     char book = bookOrder[i];
//     int whereBookIsInCorrect = strchr(bookSteps, book) - bookSteps;
//     if (book != bookSteps[i])
//     {
//       int distance = whereBookIsInCorrect - i;
//       if (distance > 5)
//       {
//         printf("A Database Systems student read a book.\n");
//         return 0;
//       }
//       numReads += distance;
//       memmove(bookSteps + i + 1, bookSteps + i, whereBookIsInCorrect - i);
//       bookSteps[i] = book;
//     }
//   }
//   printf("%d\n", numReads);

//   return 0;
// }
