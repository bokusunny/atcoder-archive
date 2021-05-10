from bisect import bisect
n = int(input())
card_list = [int(input()) for _ in range(n)]
INF = 10**30

table = [INF]*(n+1)

for c in card_list:
  i = bisect(table, c)
  table[i] = c

for i in range(n+1):
  if table[i] == INF:
    asc_card_num = i
    break

print(n-i)