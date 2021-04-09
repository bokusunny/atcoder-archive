import sys
input = sys.stdin.readline

N, Y = map(int, input().split())

for man_num in reversed(range(N+1)):
  if 10000 * man_num > Y:
    continue
  nokori1 = N - man_num
  for gosen_num in reversed(range(nokori1+1)):
    if 10000 * man_num + 5000 * gosen_num > Y:
      continue

    sen_num = N - man_num - gosen_num
    total = 10000 * man_num + 5000 * gosen_num + 1000 * sen_num

    if total == Y:
      print('%d %d %d' % (man_num, gosen_num, sen_num))
      exit()

print('-1 -1 -1')