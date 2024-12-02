V = int(input())
A = int(input())
F = int(input())
P = int(input())

contas = [A, F, P]

contas.sort()

contas_pagas = 0

for conta in contas:
  if V >= conta:
    V -= conta
    contas_pagas += 1

print(contas_pagas)
