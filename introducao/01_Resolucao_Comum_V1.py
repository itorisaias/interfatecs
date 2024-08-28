nota1 = float(input('Digite a nota 1: '))
nota2 = float(input('Digite a nota 2: '))
faltas = int(input('Digite as faltas: '))

media = (nota1 + nota2) / 2

if media >= 6 and faltas < 10:
    print('Aprovado')
else:
    print('Reprovado')
