#include <stdio.h>
#include <string.h>

int calcular_toques(const char *mensagem) {
  int total_toques = 0;

  for (int i = 0; mensagem[i] != '\0'; i++) {
    char c = mensagem[i];

    if (c >= 'a' && c <= 'c') total_toques += (c - 'a' + 1);
    else if (c >= 'A' && c <= 'C') total_toques += (c - 'A' + 4);
    else if (c >= 'd' && c <= 'f') total_toques += (c - 'd' + 1);
    else if (c >= 'D' && c <= 'F') total_toques += (c - 'D' + 4);
    else if (c >= 'g' && c <= 'i') total_toques += (c - 'g' + 1);
    else if (c >= 'G' && c <= 'I') total_toques += (c - 'G' + 4);
    else if (c >= 'j' && c <= 'l') total_toques += (c - 'j' + 1);
    else if (c >= 'J' && c <= 'L') total_toques += (c - 'J' + 4);
    else if (c >= 'm' && c <= 'o') total_toques += (c - 'm' + 1);
    else if (c >= 'M' && c <= 'O') total_toques += (c - 'M' + 4);
    else if (c >= 'p' && c <= 's') total_toques += (c - 'p' + 1);
    else if (c >= 'P' && c <= 'S') total_toques += (c - 'P' + 5);
    else if (c >= 't' && c <= 'v') total_toques += (c - 't' + 1);
    else if (c >= 'T' && c <= 'V') total_toques += (c - 'T' + 4);
    else if (c >= 'w' && c <= 'z') total_toques += (c - 'w' + 1);
    else if (c >= 'W' && c <= 'Z') total_toques += (c - 'W' + 5);
    else if (c == ' ') total_toques += 1; // Espaço
  }

  return total_toques;
}

int main() {
  char mensagem[201];

  fgets(mensagem, 201, stdin);

  mensagem[strcspn(mensagem, "\n")] = '\0';

  int resultado = calcular_toques(mensagem);
  printf("%d\n", resultado);

  return 0;
}
