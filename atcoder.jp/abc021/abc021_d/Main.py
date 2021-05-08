n = int(input())
k = int(input())

def my_factorial(n, mod=10**9+7):
  ans = 1
  for i in range(1, n+1):
    ans = ans * i % mod

  return ans

def my_comb(n, k, mod=10**9+7):
  return my_factorial(n, mod) * pow(my_factorial(n-k, mod), mod-2, mod) % mod * pow(my_factorial(k, mod), mod-2, mod) % mod

print(my_comb(n+k-1, k))