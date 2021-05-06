import copy
row_num, column_num = map(int, input().split())
grid = []
for _ in [0]*row_num:
  l = list(map(int, input().split()))
  grid.append(l)

ans = 0
for i in range(2**row_num):
  grid_copy = copy.deepcopy(grid)
  for j in range(row_num):
    if (i >> j & 1):
      for k in range(column_num):
        if grid_copy[j][k] == 0:
          grid_copy[j][k] = 1
        else:
          grid_copy[j][k] = 0

  omote_num = [0]*column_num
  for row in grid_copy:
    for column_i, target in enumerate(row):
      if target == 0: omote_num[column_i] += 1

  tmp = 0
  for omote in omote_num:
    if omote*2 < row_num:
      tmp += row_num-omote
    else:
      tmp += omote

  if tmp > ans: ans = tmp

print(ans)