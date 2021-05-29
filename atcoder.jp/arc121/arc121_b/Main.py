import bisect
n = int(input())
dic = {'R': [], 'B': [], 'G': []}
for i in range(2*n):
  a, c = input().split()
  a = int(a)
  dic[c].append(a)

if (len(dic['R']) % 2 == 0):
  if (len(dic['G']) % 2 == 0):
    exit(print(0))

  # GとB
  table = sorted(dic['G'])
  li = sorted(dic['B'])
  yobi = sorted(dic['R'])
else:
  if (len(dic['G']) % 2 == 0):
    # RとB
    table = sorted(dic['R'])
    li = sorted(dic['B'])
    yobi = sorted(dic['G'])
  else:
    # RとG
    table = sorted(dic['G'])
    li = sorted(dic['R'])
    yobi = sorted(dic['B'])

INF = 10**30
ans = INF
for a in li:
  i = bisect.bisect_left(table, a)
  if i != len(table):
    ans = min(ans, abs(table[i]-a))
  if i != 0:
    ans = min(ans, abs(a-table[i-1]))

tmp1 = INF
for a in yobi:
  i = bisect.bisect_left(table, a)
  if i != len(table):
    tmp1 = min(tmp1, abs(table[i]-a))
  if i != 0:
    tmp1 = min(tmp1, abs(a-table[i-1]))
tmp2 = INF
for a in yobi:
  i = bisect.bisect_left(li, a)
  if i != len(li):
    tmp2 = min(tmp2, abs(li[i]-a))
  if i != 0:
    tmp2 = min(tmp2, abs(a-li[i-1]))

ans = min(ans, tmp1+tmp2)

print(ans)