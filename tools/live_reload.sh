#!/bin/bash

# Verifica se o diretório foi passado como argumento
if [ -z "$1" ]; then
    echo "Por favor, forneça o diretório a ser monitorado."
    exit 1
fi

# Diretório raiz do projeto passado como argumento
DIR_TO_WATCH="$1"

# Verifica se o diretório existe
if [ ! -d "$DIR_TO_WATCH" ]; then
    echo "O diretório $DIR_TO_WATCH não existe."
    exit 1
fi

# Comando para iniciar o servidor Python
START_COMMAND="python3 $DIR_TO_WATCH/main.py"  # Substitua pelo comando que inicia sua aplicação

# Pega a última modificação de qualquer arquivo Python no diretório
LAST_MODIFICATION=$(find $DIR_TO_WATCH -type f -name "*.py" -exec stat -c %Y {} + | sort -n | tail -1)

# Executa o servidor Python pela primeira vez
$START_COMMAND &

# Armazena o PID do servidor em execução
PID=$!

# Função para reiniciar o servidor quando uma modificação for detectada
restart_server() {
    echo "Arquivos modificados. Reiniciando servidor..."
    kill $PID  # Mata o processo atual
    $START_COMMAND &  # Roda o comando novamente
    PID=$!  # Atualiza o PID do novo processo
}

# Loop para monitorar mudanças em qualquer arquivo .py no diretório
while true; do
    NEW_MODIFICATION=$(find $DIR_TO_WATCH -type f -name "*.py" -exec stat -c %Y {} + | sort -n | tail -1)
    
    if [ "$NEW_MODIFICATION" -ne "$LAST_MODIFICATION" ]; then
        LAST_MODIFICATION=$NEW_MODIFICATION
        restart_server
    fi
    
    sleep 1  # Pausa de 1 segundo antes de verificar novamente
done
