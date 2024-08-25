#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Estrutura para mapear códigos binários aos dígitos
typedef struct {
    char *codigo;
    int digito;
} CodigoDigito;

// Função para verificar se um código binário corresponde a um dígito
int encontrarDigito(char *binario, CodigoDigito *mapa, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (strcmp(binario, mapa[i].codigo) == 0) {
            return mapa[i].digito;
        }
    }
    return -1; // Retorna -1 se não encontrar correspondência
}

// Função para calcular o dígito verificador
int calcularDigitoVerificador(int *codigoCompleto) {
    int i, somaImpares = 0, somaPares = 0, terceiroValor, digitoVerificador;

    for (i = 0; i < 14; i++) {
        if ((i + 1) % 2 == 0)
            somaPares += codigoCompleto[i];
        else
            somaImpares += codigoCompleto[i];
    }

    terceiroValor = somaImpares + 3 * somaPares;

    if (terceiroValor % 10 == 0)
        digitoVerificador = 0;
    else
        digitoVerificador = abs(terceiroValor - (terceiroValor - (terceiroValor % 10) + 10));

    return digitoVerificador;
}

int main() {
    char entrada[100], saida[100];
    char *binario;
    int verificadorLido, primeiroDigito, digitoVerificador;
    int somaImpares = 0, somaPares = 0, terceiroValor;

    // Mapa para os códigos binários associados aos dígitos de paridade ímpar
    CodigoDigito mapEsquerdaImpares[10] = {
        {"0001101", 0},
        {"0011001", 1},
        {"0010011", 2},
        {"0111101", 3},
        {"0100011", 4},
        {"0110001", 5},
        {"0101111", 6},
        {"0111011", 7},
        {"0110111", 8},
        {"0001011", 9}
    };

    // Mapa para os códigos binários associados aos dígitos de paridade par
    CodigoDigito mapEsquerdaPares[10] = {
        {"0100111", 0},
        {"0110011", 1},
        {"0011011", 2},
        {"0100001", 3},
        {"0011101", 4},
        {"0111001", 5},
        {"0000101", 6},
        {"0010001", 7},
        {"0001001", 8},
        {"0010111", 9}
    };

    // Mapa para os códigos binários associados aos dígitos do lado direito
    CodigoDigito mapDireita[10] = {
        {"1110010", 0},
        {"1100110", 1},
        {"1101100", 2},
        {"1000010", 3},
        {"1011100", 4},
        {"1001110", 5},
        {"1010000", 6},
        {"1000100", 7},
        {"1001000", 8},
        {"1110100", 9}
    };

    // Mapa para associar as sequências de paridade com o primeiro dígito do código de barras
    int mapPrimeiroDigito[10][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 0}
    };

    // Enquanto houver linha a ser lida...
    while (fgets(entrada, sizeof(entrada), stdin)) {
        // Remove a quebra de linha
        entrada[strcspn(entrada, "\n")] = '\0';

        char *ptr = entrada;
        int i = 0;

        // Vai guardar os dígitos do lado esquerdo
        int digitosEsquerda[6];
        // Vai guardar os dígitos do lado direito
        int digitosDireita[6];
        // Vai guardar a paridade dos dígitos da esquerda (TRUE para par, FALSE para ímpar)
        int paridade[6];

        // Com os 3 primeiros dígitos sendo do left guard,
        // inicia a leitura a partir do quarto dígito,
        // separando-os de 7 em 7
        // e até chegar no central guard (índice 45)
        for (i = 3; i < 45; i += 7) {
            binario = strndup(ptr + i, 7);
            digitosEsquerda[i / 7] = encontrarDigito(binario, mapEsquerdaPares, 10);
            if (digitosEsquerda[i / 7] == -1) {
                digitosEsquerda[i / 7] = encontrarDigito(binario, mapEsquerdaImpares, 10);
                paridade[i / 7] = 0;
            } else {
                paridade[i / 7] = 1;
            }
            free(binario);
        }

        // Agora com os dígitos da direita (bem mais simples)
        // continua a leitura iniciando no próximo dígito que sucede o central guard (índice 50)
        // até chegar no código do dígito verificador (índice 85)
        for (i = 50; i < 85; i += 7) {
            binario = strndup(ptr + i, 7);
            digitosDireita[(i - 50) / 7] = encontrarDigito(binario, mapDireita, 10);
            free(binario);
        }

        // Separadamente, guarda-se o suposto código verificador que foi lido
        verificadorLido = encontrarDigito(ptr + 85, mapDireita, 10);

        // Como já se tem a sequência da paridade, pode-se procurar essa sequência no mapa da paridade
        // para retornar o primeiro dígito
        for (i = 0; i < 10; i++) {
            int j, igual = 1;
            for (j = 0; j < 6; j++) {
                if (mapPrimeiroDigito[i][j] != paridade[j]) {
                    igual = 0;
                    break;
                }
            }
            if (igual) {
                primeiroDigito = i;
                break;
            }
        }

        // Encontrado o primeiro dígito, adiciona-o no começo da lista dos dígitos da esquerda
        for (i = 5; i >= 0; i--) {
            digitosEsquerda[i + 1] = digitosEsquerda[i];
        }
        digitosEsquerda[0] = primeiroDigito;

        // Concatena os dígitos de ambos os lados em uma única lista
        int codigoCompleto[14];
        for (i = 0; i < 6; i++) {
            codigoCompleto[i] = digitosEsquerda[i];
            codigoCompleto[i + 6] = digitosDireita[i];
        }

        // Calcula o dígito verificador
        digitoVerificador = calcularDigitoVerificador(codigoCompleto);

        // Se o dígito que encontrou é igual ao lido,
        // significa que estava correto e faz a saída do código no formato XX-XXXXX-XXXXX-X
        if (digitoVerificador == verificadorLido) {
            sprintf(saida, "%d%d-%d%d%d%d%d-%d%d%d%d%d-%d", digitosEsquerda[0], digitosEsquerda[1], digitosEsquerda[2], digitosEsquerda[3], digitosEsquerda[4], digitosEsquerda[5],
                digitosDireita[0], digitosDireita[1], digitosDireita[2], digitosDireita[3], digitosDireita[4], digitosDireita[5], digitoVerificador);
        } else { // Se não forem iguais, o dígito verificador lido estava incorreto
            sprintf(saida, "barcode incorreto: lido = %d esperado = %d", verificadorLido, digitoVerificador);
        }
        printf("%s\n", saida);
    }
    return 0;
}
