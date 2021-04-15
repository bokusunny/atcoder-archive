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
N, M, X = IIS()
C_and_A_list = [LIIS() for _ in range(N)]
ans = -1
for i in range(2**N):
  levels = dict()
  for k in range(M):
    levels[k] = 0
  c_sum = 0
  for j in range(N):
    if (i >> j & 1):
      C_and_A = C_and_A_list[j]
      C = C_and_A[0]
      c_sum += C
      A_list = C_and_A[1:]
      for k in range(M):
        levels[k] = levels[k] + A_list[k]

  if min(levels.values()) >= X and (ans == -1 or ans > c_sum):
    ans = c_sum

print(ans)