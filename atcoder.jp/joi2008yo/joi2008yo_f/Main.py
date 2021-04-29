from heapq import heappop, heappush
n,k = map(int, input().split())
route_dict = {i:dict() for i in range(1, n+1)}
for _ in [0]*k:
  type, *args = map(int, input().split())
  if type == 0:
    a, b = args
    start = a
    INF = 10**30
    distance_dict = {i: INF for i in range(1, n+1)}
    h = []
    heappush(h, (0, start))
    distance_dict[a] = 0

    while h:
      (dis, node) = heappop(h)
      if dis > distance_dict[node]: continue

      for (next_node, distance) in route_dict[node].items():
        dis_to_next_node = distance_dict[node] + distance
        if not next_node in distance_dict or distance_dict[next_node] > dis_to_next_node:
          heappush(h, (dis_to_next_node, next_node))
          distance_dict[next_node] = dis_to_next_node

    print(distance_dict[b] if distance_dict[b] != INF else -1)
  elif type == 1:
    c, d, e = args
    if d in route_dict[c] and route_dict[c][d] <= e: continue

    route_dict[c][d] = route_dict[d][c] = e