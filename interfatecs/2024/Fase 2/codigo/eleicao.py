verba_disponivel = int(input())
qtd_localidades = int(input())
lista_entradas = []
dicionario_entradas = {}

for i in range(qtd_localidades):
    entrada = list(map(int, input().split(" ")))
    lista_entradas.append(entrada)
    dicionario_entradas[str(entrada)] = entrada[2]/entrada[1]
    
dicionario_entradas = dict(sorted(dicionario_entradas.items(), key=lambda item: item[1], reverse=True))

qtd_maxima = 0

for k, v in dicionario_entradas.items():
    lista_legal = eval(k)
    if lista_legal[1] < verba_disponivel:
        qtd_maxima += lista_legal[2]
        verba_disponivel -= lista_legal[1]
        
print(qtd_maxima)    