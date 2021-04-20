N, W = map(int, input().split())
dp = [[0 for _ in range(W+1)] for _ in range(N+1)]
for item_i in range(0, N):
  w, v = map(int, input().split())
  for sum_w in range(W):
    # 買わない場合
    dp[item_i+1][sum_w] = max(dp[item_i+1][sum_w], dp[item_i][sum_w])
    # 買う場合
    if sum_w+w <= W:
      dp[item_i+1][sum_w+w] = max(dp[item_i+1][sum_w+w], dp[item_i][sum_w]+v)

print(max(dp[-1]))