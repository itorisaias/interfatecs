## Referencia dos exercícios

## Programas que devem estar instalado para execução

Para ambientes Unix.
- gcc
- diff

Para ambientes Dos.
...

## Como rodar

```sh
gcc -o ./treinamento/<exercicio>/output/<nome_do_executavel> ./treinamento/<exercicio>/code/<nome_do_fonte> \
  && ./treinamento/<exercicio>/output/<nome_do_executavel> < ./treinamento/<exercicio>/entrada.txt > ./treinamento/<exercicio>/output/<nome_da_saida> \
  && diff ./treinamento/<exercicio>/output/<nome_da_saida> ./treinamento/<exercicio>/gabarito.txt
  # Caso mostre algum valor será a diferença do gabarito e saida
```
