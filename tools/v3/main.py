import v3 as problema
from in_out import read_test_input, read_input, write_output

# Bloco 1: Verificação de resultado
def verificar_resultado(entrada, esperado):
    resultado = problema.processar(*entrada)
    assert resultado == esperado, f"Esperado {esperado}, mas obteve {resultado}"
    return "Resultado correto!"

# Bloco 2: Execução de testes
def executar_testes():
    testes = read_test_input()
    for teste in testes:
        entrada = teste['input']
        esperado = teste['expected']
        try:
            print(verificar_resultado(entrada, esperado))
        except AssertionError as e:
            print(e)

# Bloco 3: Execução principal
if __name__ == '__main__':
    # Execute os testes
    executar_testes()

    # Leitura manual de entrada
    entrada = read_input()
    resultado = problema.processar(*entrada)
    write_output(resultado)
