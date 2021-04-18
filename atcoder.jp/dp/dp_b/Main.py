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
N, K = IIS()
h = LIIS()

dp = [0]
dp.append(abs(h[1]-h[0]))
for i in range(2, N):
	min_cost = dp[i-1] + abs(h[i]-h[i-1])
	for j in range(2, K+1):
		if i < j: continue
		min_cost = min(min_cost, dp[i-j]+abs(h[i]-h[i-j]))

	dp.append(min_cost)

print(dp[-1])