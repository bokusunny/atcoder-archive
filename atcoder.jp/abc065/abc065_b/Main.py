import sys
input = sys.stdin.readline

def I(): return input()
def IS(): return input().split()
def II(): return int(input())
def IIS(): return map(int, input().split())
def LIIS(): return list(map(int, input().split()))
def ZER(N): return [False for _ in range(N)]


INF = 10**30
MOD = 10**9+7
# ---------------------------------------------------
N = II()
A = [int(input()) for _ in range(N)]

current_i = 0
ans = 0
for _ in range(N):
  if current_i == 1:
    print(ans)
    exit()
  current_i = A[current_i] - 1
  ans += 1

print(-1)