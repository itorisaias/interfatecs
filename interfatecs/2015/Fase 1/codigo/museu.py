
def pintar_imagem(count_linha, count_coluna, linha, coluna, mat):
    if linha < 0 or linha >= count_linha or coluna < 0 or coluna >= count_coluna or mat[linha][coluna] != 1:
        return
    mat[linha][coluna] = 0
    pintar_imagem(count_linha, count_coluna, linha, coluna - 1, mat)
    pintar_imagem(count_linha, count_coluna, linha, coluna + 1, mat)
    pintar_imagem(count_linha, count_coluna, linha - 1, coluna, mat)
    pintar_imagem(count_linha, count_coluna, linha + 1, coluna, mat)

def buscar_quantidade_imagens(count_linha, count_coluna, mat):
    img_count = 0
    for linha in range(count_linha):
        for coluna in range(count_coluna):
            if mat[linha][coluna] == 1:
                pintar_imagem(count_linha, count_coluna, linha, coluna, mat)
                img_count += 1
    print(img_count)

def ler_quadro(linhas, colunas):
    MAX_VALUE = 15
    mat = [[0] * MAX_VALUE for _ in range(MAX_VALUE)]
    for i in range(linhas):
        colunaData = list(map(int, input().split()))
        mat[i] = colunaData
    return mat

def main():
    try:
        while True:
            colunas, linhas = map(int, input().split())
            mat = ler_quadro(linhas, colunas)
            buscar_quantidade_imagens(linhas, colunas, mat)
    except EOFError:
        pass

if __name__ == "__main__":
    main()
