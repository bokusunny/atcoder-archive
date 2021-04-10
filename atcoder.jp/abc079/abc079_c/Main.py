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
s = I()
L = []
for i in range(len(s)):
  L.append(int(s[i]))
n = len(s) - 1
for i in range(2**n):
  total = L[0]
  signs = ''
  for j in range(n):
    if ((i >> j) & 1):
      total += L[-(j+1)]
      signs += '+'
    else:
      total -= L[-(j+1)]
      signs += '-'

  if total == 7:
    print('%d%s%d%s%d%s%d=7' % (L[0], signs[-1], L[1], signs[-2], L[2], signs[-3], L[3]))
    break