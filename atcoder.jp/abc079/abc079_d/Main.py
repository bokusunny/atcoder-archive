h,w = map(int, input().split())
cost_list = [list(map(int, input().split())) for _ in range(10)]
grid = [list(map(int, input().split())) for _ in range(h)]
INF = 10**30

for k in range(10):
  for i in range(10):
    for j in range(10):
      if i == j: continue
      cost_list[i][j] = min(cost_list[i][j], cost_list[i][k]+cost_list[k][j])

ans = 0
for h_i in range(h):
  for w_i in range(w):
    val = grid[h_i][w_i]
    if val == 1 or val == -1: continue
    ans += cost_list[val][1]

print(ans)