// beecrowd | 1050
// DDD
// Adaptado por Neilor Tonin, URI  Brasil

// Timelimit: 1
// Leia um número inteiro que representa um código de DDD para discagem interurbana. Em seguida, informe à qual cidade o DDD pertence, considerando a tabela abaixo:

// Se a entrada for qualquer outro DDD que não esteja presente na tabela acima, o programa deverá informar:
// DDD nao cadastrado

// Entrada
// A entrada consiste de um único valor inteiro.

// Saída
// Imprima o nome da cidade correspondente ao DDD existente na entrada. Imprima DDD nao cadastrado caso não existir DDD correspondente ao número digitado.

// Exemplo de Entrada	Exemplo de Saída
// 11
// Sao Paulo

#include <stdio.h>

typedef struct
{
    int codigo;
    char destino[50];
} DDD;

DDD ddds[] = {
    {61, "Brasilia"},
    {71, "Salvador"},
    {11, "Sao Paulo"},
    {21, "Rio de Janeiro"},
    {32, "Juiz de Fora"},
    {19, "Campinas"},
    {27, "Vitoria"},
    {31, "Belo Horizonte"},
};

int main()
{
    int codigo;
    scanf("%d", &codigo);

    for (int i = 0; i < sizeof(ddds) / sizeof(ddds[0]); i++)
        if (ddds[i].codigo == codigo)
        {
            printf("%s\n", ddds[i].destino);
            return 0;
        }

    printf("DDD nao cadastrado\n");

    return 0;
}
