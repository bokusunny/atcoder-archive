n = int(input())
INF = 10**30

ans = INF
for b in range(60):
  if 2**b>10**18: break
  a = n//2**b
  c = n%2**b
  if a+b+c<ans: ans = a+b+c

print(ans)