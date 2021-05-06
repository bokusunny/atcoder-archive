seiza_star_num = int(input())
kiten_x, kiten_y = map(int, input().split())
relative_location = []
for _ in range(seiza_star_num-1):
  current_x, current_y = map(int, input().split())
  relative_location.append((current_x-kiten_x, current_y-kiten_y))

n = int(input())
star_coordinates = set()
for i in range(n):
  x, y = map(int, input().split())
  star_coordinates.add((x, y))

mi = 0
mx = 10**6
for x,y in star_coordinates:
  is_ok = True
  for relative_x, relative_y in relative_location:
    target_x = x+relative_x
    target_y = y + relative_y
    if target_x < mi or mx < target_x or target_y < mi or mx < target_y:
      is_ok = False
      break

    if not (target_x, target_y) in star_coordinates:
      is_ok = False
      break

  if is_ok:
    print(x-kiten_x, y-kiten_y)
    break