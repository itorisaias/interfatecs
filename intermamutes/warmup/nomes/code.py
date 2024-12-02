parent_name = input().strip()

q = int(input().strip())

for _ in range(q):
  child_name = input().strip()
  if child_name[:4] == parent_name[:4]:
    print("VERIFICAR")
  else:
    print("NORMAL")
