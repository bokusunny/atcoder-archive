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
 
count_dict = dict()
for _ in range(N):
  s = I()
  ordered_s = ''.join(sorted(s))
  if ordered_s in count_dict:
    count_dict[ordered_s] = count_dict[ordered_s] + 1
  else:
    count_dict[ordered_s] = 1
 
ans = 0
for count in count_dict.values():
  if count >= 2:
    ans += count * (count - 1) // 2
 
print(ans)