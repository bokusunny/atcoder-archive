def I(): return input()
def IS(): return input().split()
def II(): return int(input())
def IIS(): return map(int, input().split())
def IIR(): return [int(input()) for _ in range(N)]
def LIIS(): return list(map(int, input().split()))
def ZER(N): return [False for _ in range(N)]


INF = 10**30
MOD = 10**9+7
# ---------------------------------------------------
from decimal import Decimal
N, K = IIS()

probability = 0
for i in range(1, N+1):
	flip_count = 0
	while i<=K-1:
		flip_count += 1
		i*=2

	probability += Decimal(1)/Decimal(N*(2**flip_count))

print(probability)