from datetime import date

codigos = []
inadimplente = 0
adimplente = 0

try:
    while True:
        codigo = input()
        codigos.append(codigo)
except EOFError:
    pass

for codigo in codigos:
    vencimento = codigo[4:10]
    valor = int(codigo[10:16])
    valor_decimal = int(codigo[16:18])
    pagamento = codigo[22:28]
    vencimento_data = date(int(f"20{vencimento[4:6]}"), int(vencimento[2:4]), int(vencimento[:2]))
    pagamento_data = date(int(f"20{pagamento[4:6]}"), int(pagamento[2:4]), int(pagamento[:2]))
    total = valor + valor_decimal / 100
    if pagamento_data > vencimento_data:
        inadimplente += total
    else:
        adimplente += total

print(f"{adimplente:.2f}-ADIMPLENTE")
print(f"{inadimplente:.2f}-INADIMPLENTE")
