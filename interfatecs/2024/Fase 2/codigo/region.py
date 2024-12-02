qtd_regioes = int(input())

limites = []
ceps_validos = []
ceps_invalidos = []

for i in range(qtd_regioes):
    cep_min, cep_max = map(str, input().replace('-', "").split(" "))
    
    limites.append((cep_min, cep_max))

for i in range(int(input())):
    cep_valido = False
    
    cep_input = input()
    cep_numero = int(cep_input.replace("-", ""))
    
    for limite in limites:
        cep_min = int(limite[0])
        cep_max = int(limite[1])
        
        if cep_numero >= cep_min and cep_numero <= cep_max:
            cep_valido = True
            
    if cep_valido:
        ceps_validos.append(cep_input)
    else:
        ceps_invalidos.append(cep_input)
    
for i in sorted(ceps_validos):
    print(i + " is served by our delivery system")

for i in sorted(ceps_invalidos):
    print(i + " is not served by our delivery system")
