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
N = II()
h_list = LIIS()

dp = [0]
dp.append(abs(h_list[1] - h_list[0]))

for i in range(2, N):
	dp.append(min(dp[i-2]+abs(h_list[i]-h_list[i-2]), dp[i-1]+abs(h_list[i]-h_list[i-1])))

print(dp[N-1])