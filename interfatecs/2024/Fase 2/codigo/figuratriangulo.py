letras = "ABCDEFGHI"
N = int(input())

# Primeira versão o(N)
# triangulo = 1
# posicao = 0
# count = 0
# for i in range(N):
#     if count == len(letras):
#         count = 0
#         triangulo += 1
#     count += 1
# print(f"{triangulo}{letras[count-1]}")

# Versão alternativa O(1)
import math
triangulo = math.ceil(N/9)
letra = letras[(N-1)%9]
print(f"{triangulo}{letra}")
