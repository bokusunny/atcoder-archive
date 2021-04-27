def main():
  n = int(input())
  int_list = list(map(int, input().split()))
  dp = [[0]*21 for _ in range(n-1)]
  dp[0][int_list[0]] = 1

  for i in range(n-2):
    for j in range(21):
      next_int = int_list[i+1]
      if dp[i][j] > 0:
        if next_int == 0:
          dp[i+1][j] += (dp[i][j]*2)
        else:
          if j+next_int <= 20:
            dp[i+1][j+next_int] += dp[i][j]
          if 0 <= j-next_int:
            dp[i+1][j-next_int] += dp[i][j]

  print(dp[-1][int_list[-1]])

main()