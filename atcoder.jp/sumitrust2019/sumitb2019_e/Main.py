n = int(input())
a_list = list(map(int, input().split()))
MOD = 10**9+7

counter = [0]*n
ans = 1
for a in a_list:
  if a == 0:
    ans *= (3-counter[0])
  else:
    ans = ans * (counter[a-1]-counter[a]) % MOD

  counter[a] += 1

print(ans)