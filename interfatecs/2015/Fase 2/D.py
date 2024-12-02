PAREDE = '*'
JOGADOR = 'I'
TESOURO = 'T'
FANTASMA = '#'
CAMINHO = ' '

N = int(input())
game = []
for _ in range(N):
    game.append(list(input()))

def is_valid(i, j):
    return 0 <= i < N and 0 <= j < N

def is_wall(i, j):
    return game[i][j] == PAREDE

def is_ghost(i, j):
    return game[i][j] == FANTASMA

def is_treasure(i, j):
    return game[i][j] == TESOURO

def is_player(i, j):
    return game[i][j] == JOGADOR

def find_player():
    for i in range(N):
        for j in range(N):
            if is_player(i, j):
                return i, j

def find_treasure():
    for i in range(N):
        for j in range(N):
            if is_treasure(i, j):
                return i, j

def find_ghosts():
    ghosts = []
    for i in range(N):
        for j in range(N):
            if is_ghost(i, j):
                ghosts.append((i, j))
    return ghosts

def bfs(start, end):
    queue = [start] # (i, j) -> 1,5
    visited = [[False for _ in range(N)] for _ in range(N)]
    visited[start[0]][start[1]] = True
    while queue:
        i, j = queue.pop(0)
        if (i, j) == end:
            return True
        for x, y in [(i, j+1), (i, j-1), (i+1, j), (i-1, j)]: # right, left, down, up
            if is_valid(x, y) and not visited[x][y] and not is_wall(x, y) and not is_ghost(x, y):
                queue.append((x, y))
                visited[x][y] = True
    return False

def main():
    player = find_player()
    treasure = find_treasure()
    ghosts = find_ghosts()
    if bfs(player, treasure):
        print('S')
    else:
        for ghost in ghosts:
            if bfs(player, ghost) and bfs(ghost, treasure):
                print('S')
                return
        print('N')

if __name__ == '__main__':
    main()
    