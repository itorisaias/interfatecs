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
        // condicao de parada
        if (A == 0 && N == 0)
            break;
        // inicializa o predio
        for (c = 0; c < A; c++)
            predio[c] = FALSE;
        // leitura dos numeros
        for (c = 0; c < N; c++)
        {
            scanf("%d", &numero);
            for (x = numero - 1; x < A; x += numero)
                predio[x] = !predio[x];
        }
        // impressao do predio
        for (c = 0; c < A; c++)
            printf("%c", predio[c] ? 'O' : 'C');
        printf("\n");
    }
    return 0;
}