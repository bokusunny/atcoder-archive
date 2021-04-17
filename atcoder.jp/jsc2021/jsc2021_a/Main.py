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
X, Y, Z = IIS()

ok = -1
ng = 10**6+1
while ng-ok > 1:
	mid = (ok+ng) // 2
	if X*mid < Y*Z:
		ok = mid
	else:
		ng = mid
print(ok)