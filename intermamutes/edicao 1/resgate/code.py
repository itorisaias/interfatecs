from math import hypot

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
  edges.sort(key=lambda e: e[2])
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

def distance(a, b):
  return hypot(b[0] - a[0], b[1] - a[1]) / 100.0

C = int(input())

for _ in range(C):
  n = int(input())
  points = []
  for _ in range(n):
    x, y = map(int, input().split())
    points.append((x, y))
  edges = []
  for i in range(n):
    for j in range(i+1, n):
      w = distance(points[i], points[j])
      edges.append((i, j, w))
  resultado = kruskal(n, edges)
  print("{:.2f}".format(resultado))
