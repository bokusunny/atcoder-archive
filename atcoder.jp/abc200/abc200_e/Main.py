n,k = map(int, input().split())

dp = [[0]*(3*n+2) for _ in range(4)]
# dp[cnt][tot] := 1～Nのいずれかであるcnt個の数を使って総和がtotとなる組合せ
dp[0][0] = 1
for cnt in range(3):
  for tot in range(2*n+1):
    dp[cnt+1][tot+1] += dp[cnt][tot]
    dp[cnt+1][tot+n+1] -= dp[cnt][tot]

  for tot in range(3*n+1):
    dp[cnt+1][tot+1] += dp[cnt+1][tot]

for tot in range(3, 3*n+1):
  if dp[3][tot] >= k:
    total = tot
    break
  k -= dp[3][tot]

for kirei in range(1, n+1):
  amari = total-kirei
  kirei_patterns = dp[2][amari]
  if k <= kirei_patterns:
    if amari-1 > n:
      ninki_max = n
      oishisa_min = amari-n
      oishisa = oishisa_min+k-1
      exit(print(kirei, oishisa, total-kirei-oishisa))
    else:
      exit(print(kirei, k, amari-k))
  k -= kirei_patterns