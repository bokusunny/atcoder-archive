h,w = map(int, input().split())
grid = []
total_black = 0
for _ in [0]*h:
  s = input()
  total_black += list(s).count('#')
  grid.append(s)

moving_list = [(0, 1), (0, -1), (1, 0), (-1, 0)]

from collections import deque
q = deque([(0,0)])
total_white_dict = {(0,0): 1}
seen_set = set()

while q:
  current_y, current_x = q.popleft()
  if (current_y, current_x) in seen_set: continue
  seen_set.add((current_y, current_x))

  for moving_y, moving_x in moving_list:
    target_y = current_y+moving_y
    target_x = current_x+moving_x

    if target_y < 0 or h-1 < target_y or target_x < 0 or w-1 < target_x: continue
    if (target_y, target_x) in seen_set or grid[target_y][target_x] == '#': continue

    q.append((target_y, target_x))
    dis = total_white_dict[(current_y, current_x)]+1
    if target_y == h-1 and target_x == w-1:
      ans = h*w-total_black-dis
      exit(print(ans))

    total_white_dict[(target_y, target_x)] = dis

print(-1)