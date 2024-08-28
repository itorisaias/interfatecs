#include <stdio.h>
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
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }

    return 0;
}
