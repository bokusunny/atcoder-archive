v_num,e_num = map(int, input().split())
INF = 10**30

table = [[INF]*v_num for _ in [0]*v_num]
for i in range(v_num):
  table[i][i] = 0
for _ in [0]*e_num:
  a,b,t = map(int, input().split())
  table[a-1][b-1] = table[b-1][a-1] = t
for k in range(v_num):
  for i in range(v_num):
    i_to_k = table[i][k]
    if k == i or i_to_k == INF: continue
    for j in range(v_num):
      k_to_j = table[k][j]
      if i == j or j == k or k_to_j == INF: continue
      table[i][j] = min(table[i][j], i_to_k+k_to_j)

ans = INF
for i in range(v_num):
  longest = max(table[i])
  if ans > longest: ans = longest

print(ans)