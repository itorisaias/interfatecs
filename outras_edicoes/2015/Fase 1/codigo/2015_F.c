// Javinha está realizando uma pesquisa sobre a popularidade das linguagens de programação como lição de casa para um curso de Linguagem de Programação na Fatec. Em uma pesquisa na web, ele encontrou alguns estatísticas sobre o uso de linguagens de programação, mas nenhuma delas o satisfez. Como ele é um participante ativo de um fórum de discussão sobre linguagem de programação técnicas, onde programadores de todo o mundo enviam suas dúvidas e opiniões, ele decidiu usar o arquivo de postagens do fórum para estimar a popularidade da programação línguas. O esboço de sua ideia é o seguinte: a popularidade de uma programação específica idioma é igual ao número de postagens em que esse idioma é citado pelo menos uma vez. Apesar desta ideia simples, podem surgir alguns problemas ao procurar uma citação num publicar. Para “C”, uma busca em um post como “como ele pode escrever um programa de computador” pode retornar dois falsos positivos: “... Consegue escrever... Computador...”. Dito isso, Javinha resolveu considerar como citar apenas o nome de um idioma com um espaço antes e depois. Além disso, a estratégia de busca ele adotará não fará distinção entre maiúsculas e minúsculas. Como você é muito esperto, Javinha pediu para você escrever um programa que automaticamente calcula a popularidade dos idiomas.

// Entrada
// A primeira linha contém um inteiro P (1 ≤ P ≤ 1000), representando o número de postagens em o arquivo do fórum. Cada uma das próximas P linhas contém uma postagem de no máximo 1000 caracteres (pode conter qualquer caractere ASCII). A próxima linha contém um inteiro N (1 ≤ N ≤ 200), representando o número de linguagens de programação cuja popularidade deve ser calculada. Cada um dos próximas N linhas contém o nome de uma linguagem de programação com no máximo 30 caracteres (pode conter qualquer caractere ASCII).

// Saída
// Produza N linhas, cada uma com o nome de uma linguagem de programação e o número de posts em que foi citado (separados por um único espaço). Os idiomas devem ser impressos no mesma ordem em que foram informados na entrada

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_POSTS 1000
#define MAX_WORDS 200
#define MAX_POST_LENGTH 1000
#define MAX_WORD_LENGTH 30

int countWordsInPost(char *post, char *word)
{
  int count_word = 0;
  char *post_copy = malloc(strlen(post) + 1);
  if (post_copy == NULL) {
    fprintf(stderr, "Erro: Falha ao alocar memória.\n");
    exit(EXIT_FAILURE);
  }

  strcpy(post_copy, post); // Copia a string de entrada para a cópia
  char *token = strtok(post_copy, " ");

  while (token != NULL)
  {
    int comp = strcasecmp(word, token);
    if (comp == 0)
      count_word++;
    token = strtok(NULL, " ");
  }

  free(post_copy); // Libera a memória alocada para a cópia da string
  return count_word;
}

int main()
{
  int count_posts, count_words;
  char posts[MAX_POSTS][MAX_POST_LENGTH], words[MAX_WORDS][MAX_WORD_LENGTH];

  scanf("%d", &count_posts);
  for (int i = 0; i < count_posts; i++)
    scanf(" %[^\n]", posts[i]);

  scanf("%d", &count_words);
  for (int i = 0; i < count_words; i++)
    scanf(" %[^\n]", words[i]);

  for (int i = 0; i < count_words; i++) {
    int count_word = 0;
    for (int j = 0; j < count_posts; j++)
      count_word += countWordsInPost(posts[j], words[i]);

    printf("%s %d\n", words[i], count_word);
  }

  return 0;
}


// V2

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define MAX_POSTS 1000
// #define MAX_LANGS 200
// #define MAX_POST_LENGTH 1000
// #define MAX_LANG_LENGTH 30

// // Função para contar ocorrências de uma palavra em uma string
// int countOccurrences(const char *post, const char *word)
// {
//   int count = 0;
//   const char *ptr = post;
//   size_t wordLen = strlen(word);

//   while ((ptr = strstr(ptr, word)) != NULL)
//   {
//     if ((ptr == post || !isalnum((unsigned char)*(ptr - 1))) &&
//         (!isalnum((unsigned char)ptr[wordLen])))
//     {
//       count++;
//       ptr += wordLen; // Avança para evitar contagem dupla da mesma palavra
//     }
//     else
//     {
//       ptr += wordLen ? wordLen : 1; // Avança pelo menos um caractere
//     }
//   }

//   return count;
// }

// int main()
// {
//   int numPosts, numLangs;
//   char posts[MAX_POSTS][MAX_POST_LENGTH];
//   char langs[MAX_LANGS][MAX_LANG_LENGTH];

//   // Ler o número de postagens
//   scanf("%d", &numPosts);
//   getchar(); // Consumir o caractere de nova linha

//   // Ler as postagens
//   for (int i = 0; i < numPosts; i++)
//   {
//     fgets(posts[i], MAX_POST_LENGTH, stdin);
//     posts[i][strcspn(posts[i], "\n")] = '\0'; // Remover o caractere de nova linha
//   }

//   // Ler o número de linguagens
//   scanf("%d", &numLangs);
//   getchar(); // Consumir o caractere de nova linha

//   // Ler as linguagens
//   for (int i = 0; i < numLangs; i++)
//   {
//     fgets(langs[i], MAX_LANG_LENGTH, stdin);
//     langs[i][strcspn(langs[i], "\n")] = '\0'; // Remover o caractere de nova linha
//   }

//   for (int i = 0; i < numLangs; i++)
//     for (int j = 0; langs[i][j] != '\0'; j++)
//       langs[i][j] = tolower(langs[i][j]);

//   for (int i = 0; i < numPosts; i++)
//     for (int j = 0; posts[i][j] != '\0'; j++)
//       posts[i][j] = tolower(posts[i][j]);

//   // Calcular e imprimir o número de ocorrências de cada linguagem
//   for (int i = 0; i < numLangs; i++)
//   {
//     int totalOccurrences = 0;
//     for (int j = 0; j < numPosts; j++)
//       totalOccurrences += countOccurrences(posts[j], langs[i]);
//     printf("%s %d\n", langs[i], totalOccurrences);
//   }

//   return 0;
// }
