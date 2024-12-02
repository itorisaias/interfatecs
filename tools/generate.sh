#!/bin/bash

# Verifica se o parâmetro nome do problema foi fornecido
if [ -z "$1" ]; then
    echo "Uso: ./generate.sh <nome_problema>"
    exit 1
fi

# Recebe o nome do problema
nome_problema=$1

# Cria o diretório com o nome do problema
mkdir -p "$nome_problema"

# Substitui espaços no nome do problema por underscores
nome_problema_formatado=$(echo "$nome_problema" | tr ' ' '_')

# Cria o arquivo nome_problema.py (lógica do problema)
cat <<EOL > "$nome_problema/${nome_problema_formatado}.py"
# Função principal que processa o problema
def processar(n1: float, n2: float) -> float:
    resultado = ((n1 * 3.5) + (n2 * 7.5)) / 11
    return float(f"{resultado:.5f}")
EOL

# Cria o arquivo in_out.py (entrada e saída)
cat <<EOL > "$nome_problema/in_out.py"
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
EOL

# Cria o arquivo main.py (executa testes e valida)
cat <<EOL > "$nome_problema/main.py"
import ${nome_problema_formatado} as problema
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
EOL

# Mensagem de conclusão
echo "Estrutura criada com sucesso no diretório '$nome_problema'."
