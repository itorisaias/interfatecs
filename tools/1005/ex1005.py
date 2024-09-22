n1: float = 0.0
n2: float = 0.0
resultado: float = 0.0

def definir_entrada(e1: float, e2: float):
    global n1, n2
    n1 = float(f"{e1:.1f}")
    n2 = float(f"{e2:.1f}")


def processar():
    global resultado
    resultado = ((n1 * 3.5) + (n2 * 7.5)) / 11
    resultado = float(f"{resultado:.5f}")
    return resultado

# Exemplo para enviar o exercício!
# Isso é ignorado no arquivo de testes, é uma abordagem muito útil e simples.
if __name__ == "__main__":
    entrada1 = float(input())
    entrada2 = float(input())

    definir_entrada(entrada1, entrada2)
    processar()
    print(resultado)
