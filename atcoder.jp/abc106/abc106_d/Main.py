def main():
  n, m, q = map(int, input().split())
  dp = [[0] * (n+1) for _ in [0] * (n+1)]

  for _ in [0] * m:
    l, r = map(int, input().split())
    dp[l][r] += 1

  for i in range(n):
    for j in range(n):
      dp[i+1][j+1] += (dp[i+1][j] + dp[i][j+1] - dp[i][j])

  for _ in [0] * q:
    p, q = map(int, input().split())
    ans = dp[q][q] - dp[q][p-1] - dp[p-1][q] + dp[p-1][p-1]
    print(ans)

main()