// numero (int float)
// string, caracteres (char)
// booleano

// estrutura de dado (vetor)
#include <stdio.h>

void imprimirTabuada(int numero) {
    for (int i = 0; i <= 10; i = i + 1) {
        printf("%d x %d = %d\n", numero, i, 8 * i);
    }
}

int calcularValorFrete(int quantidadeDeKM) {
    int valorPorKM = 10;
    return quantidadeDeKM * valorPorKM;
}

int main() {
    int idade = 22;
    int valor;
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char sexo = 'Q';
    char nome[10] = "itor";

    /*
    printf("Ola %s", nome);

    printf("Numero digitado %d", valor);

    if (valor == 88) {
        printf("Voce ganhou!");
    } else {
        printf("Voce perdeu");
    }
    */
    // printf("Digite um numero: ");
    // scanf("%d", &valor);
    // imprimirTabuada(valor);
    // vetor comeca em 0
    printf("Numero da posicao 0 do vetor e %d\n", numeros[0]);
    printf("Numero da posicao 1 do vetor e %d\n", numeros[1]);

    return 0;
}