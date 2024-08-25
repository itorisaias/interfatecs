/*
Crie um programa que receba duas notas de provas de um aluno e sua quantidade de faltas.

Se essa media for maior ou igual a 6 e a quantidade de faltas for menor ou igual a 10, o aluno passou "Aprovado".

Caso contrário, o aluno não passou "Reprovado".

Exemplo entrada:
5.2 2.0 10

Exemplo saída:
Reprovado
*/

#include <stdio.h>
// 1 - erro
// 0 - não tem erro
int main() {
    float nota1, nota2;
    int faltas;

    printf("Digite a nota 1: ");
    scanf("%f", &nota1);
    printf("Digite a nota 2: ");
    scanf("%f", &nota2);
    printf("Digite as faltas: ");
    scanf("%d", &faltas);

    float media = (nota1 + nota2) / 2;

    if (media >= 6 && faltas <= 10) {
        printf("Aprovado");
    } else {
        printf("Reprovado");
    }

    return 0;
}