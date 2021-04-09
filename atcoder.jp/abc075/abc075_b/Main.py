def I(): return input()
def IS(): return input().split()
def II(): return int(input())
def IIS(): return map(int, input().split())
def LIIS(): return list(map(int, input().split()))
def ZER(N): return [False for _ in range(N)]


INF = 10**30
MOD = 10**9+7
# ---------------------------------------------------

import sys
input = sys.stdin.readline

H, W = IIS()
grid = [[] for _ in range(H)]
for i in range(H):
  string = I()
  for j in range(W):
    grid[i].append(string[j])

for i in range(H):
  for j in range(W):
    if grid[i][j] == '#':
      continue

    val = 0
    for x in [-1, 0, 1]:
      for y in [-1, 0, 1]:
        if x == y == 0 or (i + y) < 0 or H < (i + y + 1) or (j + x) < 0 or W < (j + x + 1):
          continue

        if grid[i+y][j+x] == '#':
          val += 1

    grid[i][j] = str(val)

for i in range(H):
  string_list = grid[i]
  print(''.join(string_list))