def converter_bytes(n):
  terabytes = 0
  gigabytes = 0
  megabytes = 0
  kilobytes = 0
  bytes_remaining = 0

  terabytes = n // (1024 ** 4)
  n = n % (1024 ** 4)

  gigabytes = n // (1024 ** 3)
  n = n % (1024 ** 3)

  megabytes = n // (1024 ** 2)
  n = n % (1024 ** 2)

  kilobytes = n // 1024
  n = n % 1024

  bytes_remaining = n

  return f"{terabytes}:{gigabytes}:{megabytes}:{kilobytes}:{bytes_remaining}"

try:
  while True:
    N = int(input())
    resultado = converter_bytes(N)
    print(resultado)
except EOFError:
  pass
