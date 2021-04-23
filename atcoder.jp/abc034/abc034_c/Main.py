def my_factorial(n, mod=10**9+7):
	ans = 1
	for i in range(1, n+1):
		ans = ans * i % mod

	return ans

def my_comb(n, k, mod=10**9+7):
	return my_factorial(n, mod) * pow(my_factorial(n-k, mod), mod-2, mod) * pow(my_factorial(k, mod), mod-2, mod) % mod

MOD = 10**9+7
W, H = map(int, input().split())
print(my_comb(W+H-2, H-1, MOD))