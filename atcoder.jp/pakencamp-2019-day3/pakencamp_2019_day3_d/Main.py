n = int(input())
grid = [[0]*5 for _ in range(n)]
for i in range(5):
  row = input()
  for j in range(n):
    s = row[j]
    if s == 'R':
      color = 0
    elif s == 'B':
      color = 1
    elif s == 'W':
      color = 2
    else:
      color = 3
    grid[j][i] = color

def calc_cost(row_i):
  row = grid[row_i]
  cost_list = []
  for color in range(3):
    same_color_num = row.count(color)
    cost_list.append(5-same_color_num)
  return cost_list

INF = 10**30
dp = [[INF]*3 for _ in [0]*n]
dp[0] = calc_cost(0)
for i in range(n-1):
  next_cost_list = calc_cost(i+1)
  for j in range(3):
    for k in range(3):
      if j==k: continue
      dp[i+1][k] = min(dp[i+1][k], dp[i][j]+next_cost_list[k])


print(min(dp[-1]))