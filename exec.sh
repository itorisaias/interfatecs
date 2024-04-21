#!/bin/bash

# Pedir nome do exercício
read -p "Digite o nome do exercício: " exercicio

# Pedir nome do arquivo-fonte
read -p "Digite o nome do arquivo-fonte (com extensão): " arquivo_fonte

# Caminhos dos arquivos e diretórios
caminho_exercicio="./treinamento/$exercicio"
caminho_codigo="$caminho_exercicio/code"
caminho_saida="$caminho_exercicio/output"
entrada="$caminho_exercicio/entrada.txt"
gabarito="$caminho_saida/gabarito"

# Compilar programa
gcc -o "$caminho_saida/$arquivo_fonte.out" "$caminho_codigo/$arquivo_fonte"

# Executar o programa com a entrada e capturar a saída
"$caminho_saida/$arquivo_fonte.out" < "$entrada" > "$gabarito"

# Verificar se o gabarito está correto
diff "$gabarito" "$caminho_exercicio/gabarito.txt"

# Verificar o resultado do diff e exibir mensagem correspondente
if [ $? -eq 0 ]; then
    echo "O gabarito está correto."
else
    echo "Houve diferenças entre o gabarito e a saída gerada."
fi
