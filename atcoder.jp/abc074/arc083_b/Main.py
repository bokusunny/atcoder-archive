n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]
ans = 0
for i, row in enumerate(grid):
  for j in range(n):
    if i>=j: continue
    ans += row[j]

INF = 10**30

for k in range(n):
  for i in range(n):
    if i == k: continue
    for j in range(n):
      if i >= j or j == k or grid[i][j] == INF: continue
      if grid[i][j] > grid[i][k]+grid[k][j]:
        exit(print(-1))
      elif grid[i][j] == grid[i][k]+grid[k][j]:
        ans-=grid[i][j]
        grid[i][j] = INF

print(ans)