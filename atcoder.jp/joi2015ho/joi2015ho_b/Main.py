n = int(input())
a_list = [int(input()) for _ in range(n)]
table = a_list*2
table_size = 2*n

dp = [[0]*(table_size+1) for _ in [0]*table_size]
if n%2 == 0:
  for i in range(table_size-1):
    dp[i][i+2] = max(table[i], table[i+1])
else:
  for i in range(table_size-1):
    dp[i][i+2] = min(table[i], table[i+1])

for gap in range(3, n+1):
  for l in range(table_size-gap+1):
    r = l+gap
    if gap%2 == n%2:
      dp[l][r] = max(dp[l][r-1]+table[r-1], dp[l+1][r]+table[l])
    else:
      if table[l] < table[r-1]:
        dp[l][r] = dp[l][r-1]
      else:
        dp[l][r] = dp[l+1][r]

ans = 0
for i in range(table_size-n+1):
  tmp = dp[i][i+n]
  if tmp > ans: ans = tmp
print(ans)