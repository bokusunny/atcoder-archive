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
a_list = LIIS()

ans = 0
for l in range(N):
  min_A = a_list[l]
  for r in range(l, N):
    dish_num = r - l + 1
    min_A = min(min_A, a_list[r])
    orange = dish_num * min_A
    if orange > ans:
      ans = orange

print(ans)