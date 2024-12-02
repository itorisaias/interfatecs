# Função principal que processa o problema
def processar(n1: float, n2: float) -> float:
    resultado = ((n1 * 3.5) + (n2 * 7.5)) / 11
    return float(f"{resultado:.5f}")
