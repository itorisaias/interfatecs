#include <stdio.h>

int eh_bissexto(int ano) { return (ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0));}

void gregoriano_para_maya(int dia, int mes, int ano) {
    int dias_no_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int baktun, katun, tun, uinal, kin;
    int dias_totais, i;

    dias_totais = 0;
    for (i = -3113; i < ano; i++)
        dias_totais += eh_bissexto(i) ? 366 : 365;

    for (i = 1; i < mes; i++)
    {
        dias_totais += dias_no_mes[i - 1];
        if (i == 2 && eh_bissexto(ano)) dias_totais++;
    }

    dias_totais += dia - 11;

    printf("%d/%d/%d => %d\n", dia, mes, ano, dias_totais);
    // printf("%d.%d.%d.%d.%d\n\n", baktun, katun, tun, uinal, kin);
}

int main() {
    int dia, mes, ano;
    while (scanf("%d/%d/%d", &dia, &mes, &ano) == 3) {
        gregoriano_para_maya(dia, mes, ano);
    }

    return 0;
}
