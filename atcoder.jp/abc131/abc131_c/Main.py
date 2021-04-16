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

def lcm(x, y):
	return (x * y) // math.gcd(x, y)

A, B, C, D = IIS()
if C == D:
	divided = B//C - (A-1)//C
else:
	lcm_cd = lcm(C, D)
	divided = B//C + B//D - B//(lcm_cd) - ((A-1)//C + (A-1)//D - (A-1)//(lcm_cd))

print(B-A+1-divided)