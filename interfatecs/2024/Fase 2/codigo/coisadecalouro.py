map_calendario = {
    "jan": "janeiro",
    "fev": "fevereiro",
    "mar": "março",
    "abr": "abril",
    "mai": "maio",
    "jun": "junho",
    "jul": "julho",
    "ago": "agosto",
    "set": "setembro",
    "out": "outubro",
    "nov": "novembro",
    "dez": "dezembro"
}
dias_por_extenso = {
    "um": 1,
    "dois": 2,
    "tres": 3,
    "quatro": 4,
    "cinco": 5,
    "seis": 6,
    "sete": 7,
    "oito": 8,
    "nove": 9,
    "dez": 10,
    "onze": 11,
    "doze": 12,
    "treze": 13,
    "quatorze": 14,
    "quinze": 15,
    "dezesseis": 16,
    "dezessete": 17,
    "dezoito": 18,
    "dezenove": 19,
    "vinte": 20,
    "vinte e um": 21,
    "vinte e dois": 22,
    "vinte e tres": 23,
    "vinte e quatro": 24,
    "vinte e cinco": 25,
    "vinte e seis": 26,
    "vinte e sete": 27,
    "vinte e oito": 28,
    "vinte e nove": 29,
    "trinta": 30,
    "trinta e um": 31
}
quantidade_dias_veterano = {
    "dia": 1,
    "dias": 1,
    "semana": 7,
    "semanas": 7,
    "mes": 30,
    "meses": 30
}

def obter_dias_totais(dia, mes, meses):
    total_dias = 0
    for mes_curto, dias, mes_extenso  in meses:
        if mes == mes_extenso:
            total_dias += dia
            return total_dias
        total_dias += dias
    return -1

data_prova_extenso = input() # quatorze de outubro (data que a prova será aplicada)
qtd_dias_veterenos_extenso = input() # 1 dia (quantidade de dias utilizada para estudar pelo veterano)
data_comecou_estudar_extenso = input() # treze de outubro (data que comeceu estudar)
calendario = [] # lista de tuplas (mes_curto, qtd_dias_mes, mes_extenso) para verificar se a data existe

for i in range(12):
    mes, qtd_dias_mes = input().split(": ") # exemplo: "jan: 31"
    calendario.append((mes, int(qtd_dias_mes), map_calendario[mes]))

dia, mes = data_prova_extenso.split(" de ") # quatorze, outubro
dia_prova = dias_por_extenso[dia] # 14
mes_prova = mes # outubro

dia, mes = data_comecou_estudar_extenso.split(" de ") # treze, outubro
dia_estudo = dias_por_extenso[dia] # 13
mes_estudo = mes # outubro

qtd, unidade = qtd_dias_veterenos_extenso.split() # 1, dia
qtd = int(qtd) # 1
qtd_dias_vetereno = qtd * quantidade_dias_veterano[unidade] # 1

dias_prova = obter_dias_totais(dia_prova, mes_prova, calendario)
dias_inicio = obter_dias_totais(dia_estudo, mes_estudo, calendario)

diferenca_dias = dias_prova - dias_inicio

# "esta de brincadeira?": quando a quantidade de dias de estudo antes do dia da aplicação da prova for zero ou quando a data para começar a estudar for posterior à data da aplicação da prova;
if dias_inicio >= dias_prova:
    print("esta de brincadeira?!")
# "olha a reprovacao chegando!": quando a quantidade de dias de estudo antes da prova for de pelo menos um dia, porém inferior à quantidade de tempo que o veterano usou e informou como dica;
elif diferenca_dias < qtd_dias_vetereno:
    print("olha a reprovacao chegando!")
# "que caloura ousada!": quando a quantidade de dias de estudo antes da aplicação da prova for idêntica àquela usada pelo veterano;
elif diferenca_dias == qtd_dias_vetereno:
    print("que caloura ousada!")
# "jovem consciente!": quando a quantidade de dias de estudo antes da aplicação da prova for superior àquela usada pelo veterano.
else:
    print("jovem conscienciate!")
        
# "data nao existe!": quando o dia em que o professor agendou a aplicação da prova, ou em que Victória definiu como início dos estudos, não existir no calendário da disciplina;
