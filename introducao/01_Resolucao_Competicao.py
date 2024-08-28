while True:
    nota1, nota2, faltas = map(float, input().split(" ")) # 5.2 6.3 7.0

    if nota1 == 0 and nota2 == 0 and faltas == 0:
        break

    media = (nota1 + nota2) / 2

    if media >= 6 and faltas <= 10:
        print('Aprovado')
    else:
        print('Reprovado')
