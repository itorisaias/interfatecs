imagem = 0
h = 0
v = 0
matriz = []
 
def obter_entrada():
    try:
        h, v = map(int, input().split())
        for _ in range(v):
            lista = list(map(int, input().split()))
            matriz.append(lista)
 
    except EOFError:
        print(end="")
 
def processar():
    global imagem
    for i in range(v):
        for j in range(h):
            if matriz[i][j] == 1:
                recursivo(i,j)
                imagem += 1
 
def imprimir():
    print(imagem)
 
def recursivo(i: int, j: int):
    matriz[i][j] = 0

    # cima
    if i-1 >= 0:
        if matriz[i-1][j] == 1:
            recursivo(i-1, j)

    # baixo
    if i+1 < v:
        if matriz[i+1][j] == 1:
            recursivo(i+1, j)

    # esquerda
    if j-1 >= 0:
        if matriz[i][j-1] == 1:
            recursivo(i, j-1)

    # direita
    if j+1 < h:
        if matriz[i][j+1] == 1:
            recursivo(i, j+1)

    return

 
if __name__ == "__main__":
    obter_entrada()
    processar()
    print(imagem)