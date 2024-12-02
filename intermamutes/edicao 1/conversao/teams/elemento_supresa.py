resultado = ""
n = 1

while(n != 0):
  b = int(input())
  n = b
  kb = b // 1024
  mb = kb // 1024
  gb = mb // 1024
  tb = gb // 1024
  b = b - (kb * 1024)
  kb = kb - (mb * 1024)
  mb = mb - (gb * 1024)
  gb = gb - (tb * 1024)
  resultado += f"{tb}:{gb}:{mb}:{kb}:{b}"

  if (n != 0):
    print(resultado)
    resultado = ""
    resultado += "\\\\n"

print(resultado)
