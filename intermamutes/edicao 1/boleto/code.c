#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CODIGOS 1000
#define TAM_CODIGO 32

typedef struct
{
  struct tm vencimento;
  struct tm pagamento;
  double valor;
} Codigo;

void parse_codigo(const char *codigo, Codigo *dados)
{
  // Extrair vencimento
  sscanf(codigo + 4, "%2d%2d%2d", &dados->vencimento.tm_mday, &dados->vencimento.tm_mon, &dados->vencimento.tm_year);
  dados->vencimento.tm_mon -= 1;    // Ajustar mês (0-11)
  dados->vencimento.tm_year += 100; // Ajustar ano (anos desde 1900)
  dados->vencimento.tm_hour = dados->vencimento.tm_min = dados->vencimento.tm_sec = 0;

  // Extrair pagamento
  sscanf(codigo + 22, "%2d%2d%2d", &dados->pagamento.tm_mday, &dados->pagamento.tm_mon, &dados->pagamento.tm_year);
  dados->pagamento.tm_mon -= 1;
  dados->pagamento.tm_year += 100;
  dados->pagamento.tm_hour = dados->pagamento.tm_min = dados->pagamento.tm_sec = 0;

  // Extrair valor
  int valor_inteiro, valor_decimal;
  sscanf(codigo + 10, "%6d", &valor_inteiro);
  sscanf(codigo + 16, "%2d", &valor_decimal);
  dados->valor = valor_inteiro + valor_decimal / 100.0;
}

int main()
{
  char codigos[MAX_CODIGOS][TAM_CODIGO];
  int total_codigos = 0;
  double inadimplente = 0.0, adimplente = 0.0;

  while (fgets(codigos[total_codigos], TAM_CODIGO, stdin) != NULL)
  {
    total_codigos++;
  }

  for (int i = 0; i < total_codigos; i++)
  {
    codigos[i][strlen(codigos[i]) - 1] = '\0';
  }

  for (int i = 0; i < total_codigos; i++)
  {
    Codigo dados;
    parse_codigo(codigos[i], &dados);

    time_t vencimento_time = mktime(&dados.vencimento);
    time_t pagamento_time = mktime(&dados.pagamento);

    if (difftime(pagamento_time, vencimento_time) > 0)
    {
      inadimplente += dados.valor;
    }
    else
    {
      adimplente += dados.valor;
    }
  }

  printf("%.2f-ADIMPLENTE\n", adimplente);
  printf("%.2f-INADIMPLENTE\n", inadimplente);

  return 0;
}
