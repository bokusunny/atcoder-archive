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
A, B, W = IIS()
Wg = 1000 * W
max_possible = math.floor(Wg / A)
min_possible = math.ceil(Wg / B)
max = 0
min = 0
# 多くて1000
for i in range(min_possible, max_possible+1):
  # その合計個数のペアは存在するか
  if A * i <= Wg <= B * i:
    if i > max:
      max = i
    if min == 0:
      min = i

if min == 0:
  print('UNSATISFIABLE')
else:
  print(min, max)