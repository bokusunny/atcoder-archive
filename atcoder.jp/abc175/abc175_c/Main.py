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
X, K, D = IIS()
X = abs(X) # 対称性

if 0 <= (X - D * K):
  print((X - D * K))
  exit()

remainder = X % D
nearest_K = X // D
if remainder != 0 and remainder < (D - remainder):
  nearest_K += 1
  nearest_distance = D - remainder
else:
  nearest_distance = remainder

if (K - nearest_K) % 2 == 0:
  print(nearest_distance)
else:
  print(D - nearest_distance)