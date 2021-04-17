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
N, M = IIS()
broken_step_set = set()
for _ in range(M):
	broken_step_set.add(int(input()))

dp = [1]
if 1 in broken_step_set:
	dp.append(0)
else:
	dp.append(1)

for i in range(2, N+1):
	if i in broken_step_set:
		dp.append(0)
	elif dp[i-1] == 0 and dp[i-2] == 0:
		print(0)
		exit()
	else:
		dp.append(dp[i-1]+dp[i-2])

print(dp[N] % MOD)