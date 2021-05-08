v, e = map(int, input().split())
par = [i for i in range(v)]
rank = [0] * v
same_v_count = [1]*v

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
    same_v_count[x] += same_v_count[y]
  elif rank[x] < rank[y]:
    par[x] = y
    same_v_count[y] += same_v_count[x]
  else:
    par[x] = y
    rank[y] += 1
    same_v_count[y] += same_v_count[x]

e_list = []
for _ in [0]*e:
  a,b = map(int, input().split())
  a -= 1
  b -= 1
  e_list.append((a,b))

import math

e_list.reverse()
ans_list = [math.comb(v, 2)]
for fr, to in e_list:
  tmp = ans_list[-1]
  if not same(fr, to):
    tmp -= same_v_count[find(fr)]*same_v_count[find(to)]
    unite(fr, to)
  ans_list.append(tmp)

ans_list.pop()
ans_list.reverse()
for ans in ans_list:
  print(ans)