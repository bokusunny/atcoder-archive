import sys
input = sys.stdin.readline

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
H, W, K = IIS()
grid = [list() for _ in range(H)]
for row in range(H):
  s = I()
  for column in range(W):
    grid[row].append(s[column])

choices = 0
for i1 in range(2**H):
  red_painted_rows = set()
  for j1 in range(H):
    if (i1 >> j1 & 1):
      red_painted_rows.add(j1)

  for i2 in range(2**W):
    black_squares = 0
    red_painted_columns = set()
    for j2 in range(W):
      if (i2 >> j2 & 1):
        red_painted_columns.add(j2)

    for row_i, row in enumerate(grid):
      if row_i in red_painted_rows:
        continue

      for column_i, square in enumerate(row):
        if column_i in red_painted_columns or square == '.':
          continue

        black_squares += 1

    if black_squares == K:
      choices += 1

print(choices)