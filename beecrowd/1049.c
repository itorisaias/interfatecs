// beecrowd | 1049
// Animal
// Por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Neste problema, você deverá ler 3 palavras que definem o tipo de animal possível segundo o esquema abaixo, da esquerda para a direita.  Em seguida conclua qual dos animais seguintes foi escolhido, através das três palavras fornecidas.



// Entrada
// A entrada contém 3 palavras, uma em cada linha, necessárias para identificar o animal segundo a figura acima, com todas as letras minúsculas.

// Saída
// Imprima o nome do animal correspondente à entrada fornecida.

#include <stdio.h>

int main()
{
    char palavra1[50], palavra2[50], palavra3[50];
    scanf("%s", palavra1);
    scanf("%s", palavra2);
    scanf("%s", palavra3);

    if (palavra1[0] == 'v')
    {
        if (palavra2[0] == 'a')
        {
            if (palavra3[0] == 'c')
            {
                printf("aguia\n");
            }
            else
            {
                printf("pomba\n");
            }
        }
        else
        {
            if (palavra3[0] == 'o')
            {
                printf("homem\n");
            }
            else
            {
                printf("vaca\n");
            }
        }
    }
    else
    {
        if (palavra2[0] == 'i')
        {
            if (palavra3[2] == 'm')
            {
                printf("pulga\n");
            }
            else
            {
                printf("lagarta\n");
            }
        }
        else
        {
            if (palavra3[0] == 'h')
            {
                printf("sanguessuga\n");
            }
            else
            {
                printf("minhoca\n");
            }
        }
    }

    return 0;
}