#include <stdio.h>
#include <stdlib.h>

// Tabela hash encadeada
// Quando houver colisão, insere-se um novo nó na lista encadeada

#define M 19

typedef struct {
    int matricula;
    char nome[50];
} Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} Lista;

Lista *tabela[M];

Pessoa criarPessoa() {
    Pessoa p;
    printf("Digite a matricula: ");
    scanf("%d", &p.matricula);
    scanf("%*c");
    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin);
    return p;
}

void imprimirPessoa(Pessoa p) {
    printf("\t%d - %s\n", p.matricula, p.nome);
}

Lista *criarLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}
void inserirInicio(Pessoa p, Lista *lista) {
    No *novo = (No *) malloc(sizeof(No));
    novo->pessoa = p;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

No *buscarNo(int matricula, No *inicio) {
    while (inicio != NULL) {
        if (inicio->pessoa.matricula == matricula)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL;
}

void imprimirLista(No *inicio) {
    while (inicio != NULL) {
        imprimirPessoa(inicio->pessoa);
        inicio = inicio->proximo;
    }
}

void inicializarTabela() {
    for (int i = 0; i < M; i++)
        tabela[i] = criarLista();
}

int funcaoHash(int matricula) {
    return matricula % M;
}

void inserirTabela() {
    Pessoa p = criarPessoa();
    int posicao = funcaoHash(p.matricula);
    inserirInicio(p, tabela[posicao]);
}

Pessoa* buscarPessoa(int matricula) {
    int posicao = funcaoHash(matricula);
    No *no = buscarNo(matricula, tabela[posicao]->inicio);
    if (no == NULL)
        return NULL;
    else
        return &no->pessoa;
}

void imprimirTabela() {
    printf("\n-------Tabela--------\n");
    for (int i = 0; i < M; i++) {
        printf("[%d] (size: %d)\n", i, tabela[i]->tamanho);
        imprimirLista(tabela[i]->inicio);
    }
    printf("\n---------------------\n");
}

int main() {
    printf("Tabela hash encadeada\n");

    int opcao;

    inicializarTabela();    

    do {
        printf("\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n0 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        scanf("%*c");

        switch (opcao) {
            case 1: {
                inserirTabela();
                break;
            }
            case 2: {
                int matricula;
                printf("Digite a matricula: ");
                scanf("%d", &matricula);
                Pessoa *p = buscarPessoa(matricula);
                if (p != NULL)
                    imprimirPessoa(*p);
                else
                    printf("Pessoa nao encontrada\n");
                break;
            }
            case 3: {
                imprimirTabela();
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}