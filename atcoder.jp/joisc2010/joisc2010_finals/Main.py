city_num, road_num, hold_city_num = map(int, input().split())
par = [i for i in range(city_num)]
rank = [0] * city_num

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

  return True

from heapq import heappop, heappush
h = []
for _ in [0]*road_num:
  from_city, to_city, fee = map(int, input().split())
  from_city -= 1
  to_city -= 1
  heappush(h, (fee, from_city, to_city))

tree_num = city_num
ans = 0
while tree_num > hold_city_num:
  fee, from_city, to_city = heappop(h)
  if unite(from_city, to_city):
    tree_num -= 1
    ans += fee

print(ans)