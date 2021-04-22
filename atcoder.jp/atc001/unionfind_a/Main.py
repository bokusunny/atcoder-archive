N, Q = map(int, input().split())
par = [i for i in range(N)]
rank = [0] * N

def find(x):
  if par[x] == x:
      return x
  else:
      par[x] = find(par[x]) #経路圧縮
      return par[x]

def same(x, y):
  return find(x) == find(y)

def unite(x, y):
  x = find(x)
  y = find(y)
  if x == y: return False
  if rank[x] > rank[y]:
    rank[y] = x
  elif rank[x] < rank[y]:
    rank[x] = y
  else:
    rank[x] = y
    rank[y] += 1

  par[x] = y

for i in range(Q):
  p,a,b = map(int,input().split())
  if p == 0:
      unite(a,b)
  else:
      if same(a,b):
          print('Yes')
      else:
          print('No')