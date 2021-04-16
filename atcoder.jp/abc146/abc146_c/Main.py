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
A, B, X = IIS()
def is_ok(i):
    return A * i + B * len(str(i)) <= X

ok = 0
ng = 10**9 + 1
while ng-ok > 1:
    mid = (ok+ng) // 2
    if is_ok(mid):
        ok = mid
    else:
        ng = mid
print(ok)