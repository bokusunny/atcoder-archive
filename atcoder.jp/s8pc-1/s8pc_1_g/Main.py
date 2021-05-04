n,m = map(int, input().split())
all_edges = dict()
for _ in [0]*m:
  fr, to, dis, limit = map(int, input().split())
  if fr-1 in all_edges:
    all_edges[fr-1].append((to-1, dis, limit))
  else:
    all_edges[fr-1] = [(to-1,dis,limit)]
  if to-1 in all_edges:
    all_edges[to-1].append((fr-1, dis, limit))
  else:
    all_edges[to-1] = [(fr-1,dis,limit)]


INF = 10**30
dp = [[INF]*n for _ in [0]*(2**n)]
dp_path_count = [[0]*n for _ in [0]*(2**n)]
dp[1][0] = 0
dp_path_count[1][0] = 1

for i in range(2**n):
  for fr in range(n):
    if dp[i][fr] == INF or not fr in all_edges: continue
    edges = all_edges[fr]
    for (to, dis, limit) in edges:
      if i >> to & 1 or dp[i][fr]+dis > limit: continue
      if dp[i+2**to][to] > dp[i][fr]+dis:
        dp[i+2**to][to] = dp[i][fr]+dis
        dp_path_count[i+2**to][to] = dp_path_count[i][fr]
      elif dp[i+2**to][to] == dp[i][fr]+dis:
        dp_path_count[i+2**to][to] += dp_path_count[i][fr]


count = 0
min_dis = INF
to_start_edges = all_edges[0]
for to,dis,limit in to_start_edges:
  tmp = dp[-1][to]+dis
  if tmp <= limit:
    if tmp == min_dis:
      count += dp_path_count[-1][to]
    elif tmp < min_dis:
      min_dis = tmp
      count = dp_path_count[-1][to]

if min_dis == INF:
  print('IMPOSSIBLE')
else:
  print(min_dis, count)