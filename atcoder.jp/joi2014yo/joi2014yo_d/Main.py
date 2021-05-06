MOD = 10**4+7
n = int(input())
s_list = list(input())
sekininsha_list = []
for s in s_list:
  if s == 'J':
    sekininsha_list.append(0)
  elif s == 'O':
    sekininsha_list.append(1)
  elif s == 'I':
    sekininsha_list.append(2)

dp = [[0]*8 for _ in range(n+1)]

dp[0][1] = 1
for i in range(n):
  for current_members in range(8):
    if dp[i][current_members] == 0: continue
    for next_members in range(8):
      if current_members & next_members == 0: continue
      if not (next_members >> sekininsha_list[i] & 1): continue

      dp[i+1][next_members] = (dp[i+1][next_members] + dp[i][current_members]) % MOD

ans = 0
for a in dp[-1]:
  ans = (ans + a) % MOD

print(ans)