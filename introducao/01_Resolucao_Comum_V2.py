while True:
    nota1 = float(input('Digite a nota 1: '))
    nota2 = float(input('Digite a nota 2: '))
    faltas = int(input('Digite as faltas: '))

    if nota1 == 0 and nota2 == 0 and faltas == 0:
        break

    media = (nota1 + nota2) / 2

    if media >= 6 and faltas < 10:
        print('Aprovado')
    else:
        print('Reprovado')
