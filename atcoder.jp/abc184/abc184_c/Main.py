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
r1, c1 = IIS()
r2, c2 = IIS()
horizontal_distance = abs(r2-r1)
vertical_distance = abs(c2-c1)
diff = abs(horizontal_distance-vertical_distance)

if horizontal_distance == 0 and vertical_distance == 0:
  print(0)
elif horizontal_distance + vertical_distance <= 3 or horizontal_distance == vertical_distance:
  print(1)
elif diff % 2 == 0 or diff <= 3 or horizontal_distance + vertical_distance <= 6:
  print(2)
else:
  print(3)