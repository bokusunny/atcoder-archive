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
A1 = LIIS()
A2 = LIIS()
tmp = A1[0] + sum(A2)
most = tmp

for i in range(N):
  if i == 0:
    continue
  tmp = tmp + A1[i] - A2[i-1]

  if tmp > most:
    most = tmp

print(most)