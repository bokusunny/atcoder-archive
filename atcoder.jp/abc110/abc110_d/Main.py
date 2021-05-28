def prime_factorize(n):
  res = []
  i = 2
  for i in range(2, int(-(-n**0.5//1))+1):
    if (n%i != 0): continue
    ex = 0
    while (n%i == 0):
      ex += 1
      n //= i

    res.append((i, ex))

  if n != 1: res.append((n, 1))
  return res

def my_factorial(n, mod=10**9+7):
  ans = 1
  for i in range(1, n+1):
    ans = ans * i % mod

  return ans

def my_comb(n, k, mod=10**9+7):
  return my_factorial(n, mod) * pow(my_factorial(n-k, mod), mod-2, mod) % mod * pow(my_factorial(k, mod), mod-2, mod) % mod

n,m = map(int, input().split())
pf = prime_factorize(m)
MOD = 10**9+7
ans=1
for p in pf:
  ex=p[1]
  ans = (ans * my_comb(ex+n-1, n-1))%MOD

print(ans)