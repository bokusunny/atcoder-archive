city_num, road_num = map(int, input().split())
taxi_list = []
for _ in range(city_num):
  cost, dis = map(int, input().split())
  taxi_list.append((cost, dis))

road_list = [[] for _ in range(city_num)]
for _ in range(road_num):
  fr, to = map(int, input().split())
  fr-=1
  to-=1
  road_list[fr].append(to)
  road_list[to].append(fr)

def get_reachable_cities(origin_city):
  dis = taxi_list[origin_city][1]
  from collections import deque

  def bfs(start_node):
    cities = []
    dist = [-1]*city_num
    q = deque([start_node])
    dist[start_node] = 0

    while q:
      current_node = q.popleft()
      if dist[current_node] == dis: continue
      next_nodes = road_list[current_node]
      for next_node in next_nodes:
        if dist[next_node] != -1: continue
        q.append(next_node)
        cities.append(next_node)
        dist[next_node] = dist[current_node]+1

    return cities

  return bfs(origin_city)

from heapq import heappop, heappush
INF = 10**30

h = []
min_cost = [INF]*city_num
min_cost[0] = 0
taxi_1_cost = taxi_list[0][0]
for target_city in get_reachable_cities(0):
  if target_city==city_num-1:
    exit(print(taxi_1_cost))
  min_cost[target_city] = taxi_1_cost
  heappush(h, (taxi_1_cost, target_city))

while h:
  cost, city = heappop(h)
  if min_cost[city]<cost: continue

  for target_city in get_reachable_cities(city):
    cost_to_target_city = cost+taxi_list[city][0]
    if min_cost[target_city]<cost_to_target_city: continue

    min_cost[target_city] = cost_to_target_city
    heappush(h, (cost_to_target_city, target_city))

print(min_cost[city_num-1])