building_num, wanna_see_num = map(int, input().split())
h_list = list(map(int, input().split()))
INF = 10**30

if building_num == 1 or wanna_see_num == 1: exit(print(0))

ans = INF
for i in range(2**(building_num-1)):
  if bin(i).count('1') != wanna_see_num-1: continue

  target_buildings = set()
  for j in range(building_num-1):
    if i >> j & 1: target_buildings.add(j+1)

  max_height = h_list[0]
  tmp_cost = 0
  for i in range(1, building_num):
    if i in target_buildings:
      h = h_list[i]
      if h < max_height+1:
        max_height += 1
        tmp_cost += max_height-h
      else:
        max_height = h
    else:
      if h_list[i] > max_height:
        max_height = h_list[i]

  if tmp_cost < ans: ans = tmp_cost

print(ans)