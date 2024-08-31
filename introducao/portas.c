#include <stdio.h>

#define MAX_TAM 100
#define TRUE 1
#define FALSE 0

int main()
{
    char predio[MAX_TAM];
    int i, A, N, x, numero;
    while (TRUE)
    {
        scanf("%d %d", &A, &N);
        if (A == 0 && N == 0) // condicao de parada
            break;
        for (i = 0; i < A; i++) // inicializa o predio
            predio[i] = FALSE;
        for (i = 0; i < N; i++) // leitura dos numeros
        {
            scanf("%d", &numero);
            for (x = numero - 1; x < A; x += numero)
                predio[x] = !predio[x];
        }
        for (i = 0; i < A; i++) // impressao do predio
            printf("%c", predio[i] ? 'O' : 'C');
        printf("\n");
    }
    return 0;
}