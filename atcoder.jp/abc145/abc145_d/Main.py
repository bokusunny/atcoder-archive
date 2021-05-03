x,y = map(int, input().split())

def my_factorial(n, mod=10**9+7):
  ans = 1
  for i in range(1, n+1):
    ans = ans * i % mod

  return ans

def my_comb(n, k, mod=10**9+7):
  return my_factorial(n, mod) * pow(my_factorial(n-k, mod), mod-2, mod) * pow(my_factorial(k, mod), mod-2, mod) % mod

if (2*x-y)%3 != 0 or (2*y-x)%3 != 0 or (2*x-y) < 0 or (2*y-x) < 0: exit(print(0))

n = (x+y)//3
k = (2*y-x)//3

print(my_comb(n,k))