import sys
sys.setrecursionlimit(10**9)

city_num, road_num, zombie_city_num, danger_range = map(int, input().split())
p,q = map(int, input().split())
zombie_city_list = [int(input())-1 for _ in range(zombie_city_num)]
zombie_city_set = set(zombie_city_list)
road_dict = {i:[] for i in range(city_num)}
for _ in range(road_num):
  fr, to = map(int, input().split())
  fr -= 1
  to -= 1
  road_dict[fr].append(to)
  road_dict[to].append(fr)

from collections import deque
from copy import deepcopy
dangerous_city_set = set()

def bfs(start_city):
  INF = 10**30
  dist = [INF]*city_num
  q = deque([start_city])
  dist[start_city] = 0

  while q:
    current_city = q.popleft()
    if dist[current_city] > danger_range: break
    if not current_city in zombie_city_set:
      dangerous_city_set.add(current_city)

    next_cities = road_dict[current_city]
    for next_city in next_cities:
      if dist[next_city] != INF: continue
      q.append(next_city)
      dist[next_city] = dist[current_city]+1

for zombie_city in zombie_city_list:
  bfs(zombie_city)

from heapq import heappop, heappush
INF = 10**30

dis_dict = {i: INF for i in range(city_num)}
h = []
heappush(h, (0, 0))
dis_dict[0] = 0

while h:
  dis, current = heappop(h)
  if dis > dis_dict[current]: continue

  next_cities = road_dict[current]
  for next_city in next_cities:
    if next_city in zombie_city_set:
      continue
    elif next_city == city_num-1:
      exit(print(dis))
    elif next_city in dangerous_city_set:
      if dis_dict[next_city] > dis+q:
        heappush(h, (dis+q, next_city))
        dis_dict[next_city] = dis+q
    else:
      if dis_dict[next_city] > dis+p:
        heappush(h, (dis+p, next_city))
        dis_dict[next_city] = dis+p