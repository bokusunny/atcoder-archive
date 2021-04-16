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
# 2019 = 3 * 673
L, R = IIS()
if R - L >= 2018:
	print(0)
	exit()

ans = 2019 # impossible
for i in range(L, R+1):
	for j in range(i+1, R+1):
		mod = (i * j) % 2019
		if mod == 0:
			print(0)
			exit()
		elif mod < ans:
			ans = mod

print(ans)