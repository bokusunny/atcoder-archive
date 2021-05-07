import copy
import sys
sys.setrecursionlimit(10**9)

w = int(input())
h = int(input())

moving_list = [(0, 1), (0, -1), (1, 0), (-1, 0)]

grid = []
for i in range(h):
  li = list(map(int, input().split()))
  grid.append(li)

ans = 0
def dfs(h_i, w_i, seen_set):
  seen_set.add((h_i, w_i))
  for moving in moving_list:
    target_h = h_i+moving[0]
    target_w = w_i+moving[1]

    if target_h < 0 or h-1 < target_h or target_w < 0 or w-1 < target_w or (target_h, target_w) in seen_set or grid[target_h][target_w] == 0:
      tmp = len(seen_set)
      global ans
      if ans < tmp: ans = tmp
      continue

    dfs(target_h, target_w, copy.deepcopy(seen_set))


for h_i in range(h):
  for w_i in range(w):
    if grid[h_i][w_i] == 0: continue

    dfs(h_i, w_i, set())

print(ans)