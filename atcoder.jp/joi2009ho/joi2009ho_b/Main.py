total_d = int(input())
shop_n = int(input())
order_n = int(input())

s_list = [0, total_d]
for _ in range(shop_n-1):
  d = int(input())
  s_list.append(d)

s_list.sort()

import bisect
total = 0
for _ in range(order_n):
  k = int(input())
  i = bisect.bisect(s_list, k)
  min_d = min(s_list[i]-k, k-s_list[i-1])
  total += min_d

print(total)