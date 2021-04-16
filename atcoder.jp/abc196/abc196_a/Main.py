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
a, b = IIS()
c,d = IIS()
ans = -200
for x in range(a, b+1):
	for y in range(c, d+1):
		ans = max(ans, x-y)

print(ans)