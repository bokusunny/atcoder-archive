n, m = map(int, input().split())

ab_list = []
for _ in range(m):
  a, b = map(int, input().split())
  ab_list.append((a-1, b-1))

cut_edge_num = 0
for i in range(m):
  par = [i for i in range(n)]
  rank = [0] * n

  def find(x):
    if par[x] == x:
      return x
    else:
      par[x] = find(par[x])
      return par[x]

  def same(x, y):
    return find(x) == find(y)

  def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y: return False

    if rank[x] > rank[y]:
      par[y] = x
    elif rank[x] < rank[y]:
      par[x] = y
    else:
      par[x] = y
      rank[y] += 1

  for ab_i, ab in enumerate(ab_list):
    if ab_i == i: continue
    unite(ab[0], ab[1])

  is_cut_edge = False
  for j in range(n):
    if not same(0, j):
      is_cut_edge = True
      break

  if is_cut_edge: cut_edge_num+= 1

print(cut_edge_num)