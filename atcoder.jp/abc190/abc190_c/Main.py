import sys
input = sys.stdin.readline

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
conditions = [LIIS() for _ in range(M)]
K = II()
strategies = [LIIS() for _ in range(K)]

ans = 0
for i in range(2**K):
  balls = set()
  for j in range(K):
    if (i >> j & 1):
      balls.add(strategies[j][0])
    else:
      balls.add(strategies[j][1])

  count = sum(A in balls and B in balls for A, B in conditions)
  if count > ans:
    ans = count

print(ans)