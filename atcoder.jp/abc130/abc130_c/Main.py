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
W, H, x, y = IIS()
if x*2==W and y*2==H:
	print(W*H/2, 1)
else:
	print(W*H/2, 0)