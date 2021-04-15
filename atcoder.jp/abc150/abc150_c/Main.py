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

N = II()
P_list = LIIS()
Q_list = LIIS()

def count_nums_less_than(l):
  val = 0
  unchosen_nums = [i for i in range(1, N+1)]
  for i, p_or_q in enumerate(l, 1):
    n = 0
    for num in unchosen_nums:
      if num < p_or_q:
        n += 1

    val += (n * math.factorial(N - i))
    unchosen_nums.remove(p_or_q)

  return val

a = count_nums_less_than(P_list) + 1
b = count_nums_less_than(Q_list) + 1

print(abs(a-b))