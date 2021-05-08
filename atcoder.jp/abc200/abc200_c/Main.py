n = int(input())
a_list = list(map(int, input().split()))

dic = dict()
for a in a_list:
  a%= 200
  if a in dic:
    dic[a] += 1
  else:
    dic[a] = 1

import math

ans = 0
for val in dic.values():
  ans += math.comb(val, 2)

print(ans)