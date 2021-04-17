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
A_set = set(LIIS())
B_set = set(LIIS())
AB_union = A_set | B_set

ans = list()
for i in AB_union:
	if i in A_set and i in B_set:
		continue

	ans.append(i)

ans.sort()
print(*ans)