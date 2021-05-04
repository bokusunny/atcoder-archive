import sys
sys.setrecursionlimit(10**9)

w,h = map(int, input().split())
grid = []
for _ in [0]*h:
  location_list = list(map(int, input().split()))
  grid.append(location_list)

def check_list(height_i, width_i):
  l = []
  to_check_height = []
  to_check_width = [0]
  if height_i != 0: to_check_height.append(-1)
  if height_i != h-1: to_check_height.append(1)
  if height_i%2 == 0:
    if width_i != w-1: to_check_width.append(1)
  else:
    if width_i != 0: to_check_width.append(-1)

  for height_diff in to_check_height:
    for width_diff in to_check_width:
      l.append((height_i+height_diff, width_i+width_diff))

  if width_i != 0: l.append((height_i, width_i-1))
  if width_i != w-1: l.append((height_i, width_i+1))

  return l

def all_check_list(height_i, width_i):
  l = [(height_i, width_i+1), (height_i, width_i-1), (height_i+1, width_i), (height_i-1, width_i)]
  if height_i%2 == 0:
    l.append((height_i+1, width_i+1))
    l.append((height_i-1, width_i+1))
  else:
    l.append((height_i+1, width_i-1))
    l.append((height_i-1, width_i-1))
  return l

def is_rounded(height_i, width_i, seen_set):
  if height_i < 0 or h-1 < height_i or width_i < 0 or w-1 < width_i:
    return False, seen_set
  if grid[height_i][width_i] == 1 or (height_i, width_i) in seen_set:
    return True, seen_set

  seen_set.add((height_i, width_i))

  adjacent_list = all_check_list(height_i, width_i)
  for adjacent in adjacent_list:
    if not adjacent in seen_set:
      is_round, _ = is_rounded(*adjacent, seen_set)
      if not is_round:
        return False, seen_set

  return True, seen_set


all_rounded_set = set()
all_not_rounded_set = set()
total = 0
for height_i in range(h):
  for width_i in range(w):
    if grid[height_i][width_i] == 1:
      if width_i == 0:
        total += 1
      if width_i == w-1:
        total += 1
      if height_i == 0:
        total += 2
      if height_i == h-1:
        total += 2
      if width_i == 0 and height_i%2 == 1:
        if height_i == h-1:
          total += 1
        else:
          total += 2
      if width_i == w-1 and height_i%2 == 0:
        if height_i == 0 or height_i == h-1:
          total += 1
        else:
          total += 2
    else:
      if (height_i, width_i) in all_rounded_set:
        continue
      if not (height_i, width_i) in all_not_rounded_set:
        is_round, returned_set = is_rounded(height_i, width_i, set())
        if is_round:
          all_rounded_set |= returned_set
          continue
        else:
          all_not_rounded_set |= returned_set
      adjacent_list = check_list(height_i, width_i)
      for adjacent in adjacent_list:
        if grid[adjacent[0]][adjacent[1]] == 1:
          total += 1

print(total)