MAX_TAM = 100
TRUE = True
FALSE = False

while TRUE:
    A, N = map(int, input().split())
    # Condição de parada
    if A == 0 and N == 0:
        break
    
    # Inicializa o prédio
    predio = [FALSE] * A
    
    # Leitura dos números
    for _ in range(N):
        numero = int(input())
        for x in range(numero - 1, A, numero):
            predio[x] = not predio[x]
    
    # Impressão do prédio
    print(''.join(['O' if p else 'C' for p in predio]))
