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
all = (10**N) % MOD
no_zero_patterns = (9**N) % MOD
no_nine_patterns = no_zero_patterns
no_zero_nor_nice_patterns = (8**N) % MOD

print((all - no_zero_patterns - no_nine_patterns + no_zero_nor_nice_patterns) % MOD)