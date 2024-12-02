l, c, n, cl, cc = map(int, input().split(" "))
caminho = input().upper()

for d in caminho:
    if d == 'C':
        cl += 1
    if d == 'B':
        cl -= 1
        
    if d == 'E':
        cc += 1
    if d == 'D':
        cc -= 1

if (cc < 0 or cl < 0) or (cc >= 10 or cl >= 10):
    cc = -1
    cl = -1

print(cl, cc)