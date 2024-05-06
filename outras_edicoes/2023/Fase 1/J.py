entrada: str
letrasPermitidas = "abcdefghifjklmnopqrstuvwxyz123456789"

def verificar_palindromo():
  entrada_formatada = ""
  for c in entrada:
      if c in letrasPermitidas:
          entrada_formatada += c
  return entrada_formatada == entrada_formatada[::-1]

def imprimir_resposta():
  if verificar_palindromo():
      print("Parabéns, você encontrou o Palíndromo Perdido!")
  else:
      print("A busca continua, o Palíndromo Perdido ainda não foi encontrado.")

if __name__ == "__main__":
  while True:
      entrada = input().lower()
      if entrada == "eof":
          break
      imprimir_resposta()
