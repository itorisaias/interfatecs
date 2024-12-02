class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1


def kruskal(n, edges):
    edges.sort(key=lambda x: x[2])
    uf = UnionFind(n)
    mst_cost = 0
    edges_used = 0

    for u, v, w in edges:
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            mst_cost += w
            edges_used += 1
            if edges_used == n - 1:
                break

    return mst_cost

E, L = map(int, input().split())
edges = []

for _ in range(L):
    X, Y, Z = map(int, input().split())
    edges.append((X - 1, Y - 1, Z))

resultado = kruskal(E, edges)
print(resultado)
