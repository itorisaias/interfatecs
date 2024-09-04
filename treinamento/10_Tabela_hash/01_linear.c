#include <stdio.h>
#include <stdlib.h>

// Tabela hash linear

// Tamanho será de 10 elementos então pego o dobro e acho primo mais perto
// Em caso de colisão, incremento a posição e inserir na próxima posição livre
#define M 19

typedef struct {
    int matricula;
    char nome[50];
} Pessoa;

Pessoa tabelaHash[M];

void inicializaTabela() {
    for (int i = 0; i < M; i++) {
        tabelaHash[i].matricula = -1;
    }
}

int funcaoHash(int matricula) {
    return matricula % M;
}

Pessoa lerPessoa() {
    Pessoa p;
    printf("Digite a matricula: ");
    scanf("%d", &p.matricula);
    scanf("%*c");
    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin);
    return p;
}

void insere() {
    Pessoa p = lerPessoa();
    int posicao = funcaoHash(p.matricula);
    while (tabelaHash[posicao].matricula != -1)
        posicao = funcaoHash(posicao + 1);
    tabelaHash[posicao] = p;
}

Pessoa* buscar(int matricula) {
    int posicao = funcaoHash(matricula);
    while (tabelaHash[posicao].matricula != -1) {
        if (tabelaHash[posicao].matricula == matricula)
            return &tabelaHash[posicao];
        else
            posicao = funcaoHash(posicao + 1);
    }
    return NULL;
}

void imprimeTabela() {
    printf("\n-------Tabela Hash--------\n");
    for (int i = 0; i < M; i++)
        if (tabelaHash[i].matricula != -1)
            printf("[%d] \t %d - %s", i, tabelaHash[i].matricula, tabelaHash[i].nome);
        else
            printf("[%d] vazia\n", i);
    printf("\n--------------------------\n");
}

int main() {
    int opcao;
    inicializaTabela();
    do {
        printf("1 - Inserir\n2 - Buscar\n3 - Imprimir\n0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                insere();
                break;
            case 2:
                printf("Digite a matricula: ");
                int matricula;
                scanf("%d", &matricula);
                Pessoa* p = buscar(matricula);
                if (p != NULL)
                    printf("Encontrado: %d - %s\n", p->matricula, p->nome);
                else
                    printf("Não encontrado\n");
                break;
            case 3:
                imprimeTabela();
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}