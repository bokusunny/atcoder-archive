n,k = map(int, input().split())
mod = 10**4
decided_dic = dict()
for _ in [0]*k:
  a,b = map(int, input().split())
  decided_dic[a-1] = b-1
# dp[i][a][b]: i-2日目がa, i-1日目がbであるようなi-1日目までのパスタの選び方の総数
dp = [[[0]*3 for _ in [0]*3] for _ in [0]*(n+1)]
dp[0][0][0] = 1 # 適当に設定、後のa==b==cのチェッカーはi>=2の条件で引っかからないように
for i in range(n):
  for a in range(3):
    for b in range(3):
      cs = [decided_dic[i]] if i in decided_dic else [0, 1, 2]
      for c in cs:
        if i>=2 and a == b == c: continue
        dp[i+1][b][c] = (dp[i+1][b][c] + dp[i][a][b]) % mod

print(sum(map(sum, dp[-1]))%mod)