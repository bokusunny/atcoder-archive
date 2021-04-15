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
N, M = IIS()
# if M == 0:
#   if N == 1:
#     print(0)
#   else:
#     print(10**(N-1))
#   exit()

req = dict()
for _ in range(M):
  s, c = IIS()
  if s in req and req[s] != c:
    print(-1)
    exit()
  else:
    req[s] = c

if N == 1:
  start = 0
else:
  start = 10**(N-1)

for i in range(start, 10**N):
  is_ans = True
  str_i = str(i)
  for sj, cj in req.items():
    if not str_i[sj-1] == str(cj):
      is_ans = False

  if is_ans:
    print(i)
    exit()

print(-1)