#include <stdio.h>
int main() {
    float nota1, nota2;
    int faltas;

    while (1) {
        scanf("%f", &nota1);
        scanf("%f", &nota2);
        scanf("%d", &faltas);

        if (nota1 == 0 && nota2 == 0 && faltas == 0)
            break;

        float media = (nota1 + nota2) / 2;

        if (media >= 6 && faltas <= 10)
            printf("Aprovado\n");
        else
            printf("Reprovado\n");
    }

    return 0;
}
