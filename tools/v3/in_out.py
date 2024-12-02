# Função para ler entrada do usuário
def read_input():
    e1 = float(input("Digite o primeiro número: "))
    e2 = float(input("Digite o segundo número: "))
    return (e1, e2)

# Função para ler a entrada esperada de testes
def read_test_input():
    # Simulação de dados de teste com entrada e esperado
    # Você pode adicionar mais parâmetros aqui se necessário
    test_data = [
        {'input': (5.0, 7.1), 'expected': 6.43182},
        {'input': (0.0, 7.1), 'expected': 4.84091},
        {'input': (10.0, 10.0), 'expected': 10.00000},
    ]
    return test_data

# Função para exibir a saída do resultado
def write_output(resultado):
    print(f"Resultado: {resultado:.5f}")
