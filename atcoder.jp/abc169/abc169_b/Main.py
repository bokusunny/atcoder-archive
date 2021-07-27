N = int(input())
A = list(map(int, input().split()))
A.sort()
ans = 1
ma = 10**18
for a in A:
  ans *= a
  if ans > ma:
    exit(print(-1))

print(ans)