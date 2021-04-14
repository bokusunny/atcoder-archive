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
N = II()
N -= 1 # 番号は0から
alphabet = 'abcdefghijklmnopqrstuvwxyz'

for i in range(1, 10000):
  if N >= (26**i):
    N -= (26**i)
    continue

  ans = ''
  for j in reversed(range(i)):
    quotient = N // (26**j)
    N %= (26**j)

    ans += alphabet[quotient]

  print(ans)
  break