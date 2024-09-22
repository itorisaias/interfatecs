import ex1005


def verificar_resultado(n1: float, n2: float, saida: float):
    ex1005.testando = True
    ex1005.definir_entrada(n1, n2)
    resultado = ex1005.processar()

    if resultado == saida:
        return "Resultado correto!"
    else:
        return "Resultado incorreto!"


print(verificar_resultado(5.0, 7.1, 6.43182))
print(verificar_resultado(0, 7.1, 4.84091))
print(verificar_resultado(10.0, 10.0, 10.00000))
