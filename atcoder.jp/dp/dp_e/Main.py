import sys
input = sys.stdin.readline

N, W = map(int, input().split())
max_v = 10**3
max_n = 10**2
max_v_sum = max_v * max_n
INF = 10**30

dp = [[INF for _ in range(max_v_sum+1)] for _ in range(N+1)]
dp[0][0] = 0

for item_i in range(N):
  w, v = map(int, input().split())
  for v_sum in range(max_v_sum+1):
    dp[item_i+1][v_sum] = min(dp[item_i+1][v_sum], dp[item_i][v_sum])
    if (v_sum+v<=max_v_sum):
      dp[item_i+1][v_sum+v] = min(dp[item_i+1][v_sum+v], dp[item_i][v_sum]+w)

res = 0
for v_sum, w in enumerate(dp[-1]):
  if w <= W:
    res = max(res, v_sum)

print(res)