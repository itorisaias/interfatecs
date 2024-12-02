# Num universo paralelo, Silvio Pranktos adora fazer jogos com pegadinhas com seus convidados. Entre eles
# estão o jogo "É, não e porquê"e o Jogo do Pim. Nesse jogo, os participantes devem contar os números em
# ordem crescente, substituindo os múltiplos de 4 pela palavra "pim". Por exemplo, os primeiros dez números
# do jogo seriam:
# 1 2 3 pim 5 6 7 pim 9 10
# Sivio desafiou os participantes a escreverem uma sequência numérica do "Jogo do Pim"e quer que você crie
# um programa para verificar se eles acertaram a sequência!
# Entrada
# A entrada consiste em um único inteiro n (1 ⩽N ⩽104), indicando o número máximo da sequência.
# Saída
# Seu programa deve imprimir uma única linha contendo a sequência até o número máximo informado.
# Exemplo de Entrada 1 Exemplo de Saída 1
# 1 1
# Exemplo de Entrada 2 Exemplo de Saída 2
# 10 1 2 3 pim 5 6 7 pim 9 10
# Maratona de Programação InterFatecs 2023 - Problema J: Pim 29

n = int(input())

for i in range(1, n + 1):
  if i % 4 == 0:
    print('pim', end=' ')
  elif i == n:
    print(i)
  else:
    print(i, end=' ')
