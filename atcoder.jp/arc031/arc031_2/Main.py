def I(): return input()
def IS(): return input().split()
def II(): return int(input())
def IIS(): return map(int, input().split())
def IIR(): return [int(input()) for _ in range(N)]
def LIIS(): return list(map(int, input().split()))
def ZER(N): return [False for _ in range(N)]


INF = 10**30
MOD = 10**9+7
# ---------------------------------------------------
import copy
import sys
sys.setrecursionlimit(10 ** 9)

L = []
o_count = 0
for i in range(10):
  s = I()
  L.append(list(s))
  if 'o' in s:
    o_count += s.count('o')

for filled_x in range(10):
  for filled_y in range(10):
    if L[filled_y][filled_x] == 'o':
      continue

    filled_L = copy.deepcopy(L)
    filled_L[filled_y][filled_x] = 'o'

    def dfs(x, y, seen_set):
      if x < 0 or 10 <= x or y < 0 or 10 <= y or (x, y) in seen_set:
        return

      if filled_L[y][x] == 'x':
        return
      if len(seen_set) == o_count:
        print('YES')
        exit()

      seen_set.add((x, y))

      dfs(x, y+1, seen_set)
      dfs(x, y-1, seen_set)
      dfs(x-1, y, seen_set)
      dfs(x+1, y, seen_set)

    dfs(filled_x, filled_y, set())

print('NO')