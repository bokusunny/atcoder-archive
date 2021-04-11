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
import math
R, X, Y = IIS()
total_distance = math.sqrt(X**2+Y**2)
if total_distance % R == 0:
  print(int(total_distance / R))
elif total_distance < R:
  print(2)
else:
  print(int(total_distance // R + 1))