def cost(co1, co2):
  x1, y1 = co1
  x2, y2 = co2
  return min(abs(x1-x2), abs(y1-y1))

n = int(input())
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

  return True

from heapq import heappop, heappush
x_sort_city_list = []
y_sort_city_list = []
for i in range(n):
  x,y = map(int, input().split())
  heappush(x_sort_city_list, (x, i))
  heappush(y_sort_city_list, (y, i))


h = []
x_sorted_list_prev = heappop(x_sort_city_list)
y_sorted_list_prev = heappop(y_sort_city_list)
for i in range(1, n):
  x1, i1 = x_sorted_list_prev
  x2, i2 = heappop(x_sort_city_list)
  cost_x = x2-x1
  heappush(h, (cost_x, i1, i2))
  x_sorted_list_prev = (x2, i2)

  y3, i3 = y_sorted_list_prev
  y4, i4 = heappop(y_sort_city_list)
  cost_y = y4-y3
  heappush(h, (cost_y, i3, i4))
  y_sorted_list_prev = (y4, i4)

ans = 0
while h:
  cost, i1, i2 = heappop(h)
  if not same(i1, i2):
    unite(i1, i2)
    ans += cost

print(ans)