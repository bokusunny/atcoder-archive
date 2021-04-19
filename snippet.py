# 最大公約数
from functools import reduce
import math

def gcd(x,y):
	return math.gcd(x, y)

def gcd_list(num_list):
	return reduce(math.gcd, num_list)

# 最小公倍数
from functools import reduce
import math

def lcm(x, y):
	return (x * y) // math.gcd(x, y)

def lcm_list(num_list):
	return reduce(lcm, num_list, 1)

# 約数列挙
def divisors(n):
	return_list = []
	for i in range(1, int(n**0.5)+1):
		if n % i == 0:
			return_list.append(i)
		if i != n // i:
			return_list.append(n//i)

	return return_list

# 素数判定
def is_prime(n):
    if n<=1: return False
    i = 2
    while i*i <= n:
			if n%i == 0: return False
			i+=1

    return True

# 素数数え上げ(エラトステネスの篩): set ver
def prime_all_set(n):
	prime_set = set([i for i in range(2, n+1)])

	i = 2
	while i*i <= n:
		if i in prime_set and is_prime(i):
			for j in range(i*2, n+1, i):
					prime_set.discard(j)

		i += 1

	return prime_set
# list ver
def prime_all_list(n):
	prime_list = [True] * (n+1)
	prime_list[0] = prime_list[1] = False

	i = 2
	while i*i <= n:
		if prime_list[i] and is_prime(i):
			for j in range(i*2, n+1, i):
				prime_list[j] = False

		i += 1

	return prime_list

# 素因数分解
def prime_factorize(n):
	return_list = []
	while n % 2 == 0:
		return_list.append(2)
		n //= 2
	f = 3
	while f * f <= n:
		if n % f == 0:
			return_list.append(f)
			n //= f
		else:
			f += 2
	if n != 1:
		return_list.append(n)
	return return_list

# 素因数分解 with SPF
def spf(n):
	spf_table = [i for i in range(n+1)]

	i = 2
	while i*i <= n:
		if is_prime(i):
			for j in range(i*2, n+1, i):
				spf_table[j] = i

		i += 1

	return spf_table

def spf_prime_factorize(n):
	spf_table = spf(n)
	l = list()
	while n > 1:
		target = spf_table[n]
		l.append(target)
		n //= spf_table[target]

	return l

# 二分探索
def is_ok(i):
	return i <= 9

ok = -1
ng = 10
while ng-ok > 1:
	mid = (ok+ng) // 2
	if is_ok(mid):
		ok = mid
	else:
		ng = mid
print(ok,ng)
