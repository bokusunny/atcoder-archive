H, W, N = map(int, input().split())

grid = [[] for _ in [0] * H]
t_grid = [[0] * W for _ in [0] * H]
for i in range(H):
  s = input()
  for j in range(W):
    grid[i].append(s[j])
    if s[j] == 'S':
      start = (i, j)

from collections import deque

moving_list = [(0, 1), (0, -1), (1, 0), (-1, 0)]
seen_set = set()
q = deque([start])
rat_power = 1
while q:
  current_y, current_x = q.popleft()

  if (current_y, current_x) in seen_set: continue
  seen_set.add((current_y, current_x))

  for mov_y, mov_x in moving_list:
    distiny_y, distiny_x = current_y+mov_y, current_x+mov_x
    distiny = (distiny_y, distiny_x)
    if distiny in seen_set or distiny_y<0 or distiny_y>H-1 or distiny_x<0 or distiny_x>W-1: continue
    distiny_str = grid[distiny_y][distiny_x]
    if distiny_str == 'X': continue

    distiny_arriving_time = t_grid[distiny_y][distiny_x] = t_grid[current_y][current_x] + 1
    if distiny_str == str(rat_power):
      if rat_power == N:
        exit(print(distiny_arriving_time))
      rat_power += 1
      q.clear()
      q.append(distiny)
      seen_set = set()
      break
    else:
      q.append(distiny)