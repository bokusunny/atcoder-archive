k,n,m = map(int, input().split())
a_list = list(map(int, input().split()))
ma_list= []
for a in a_list:
  ma_list.append(a*m)

from heapq import heappush, heappop
b_list = []
diff_list_asc = []
diff_list_dec = []# あとで-1するのに注意
b_sum = 0
for i, ma in enumerate(ma_list):
  b_tmp = ma//n
  if abs(ma-b_tmp*n) > abs((b_tmp+1)*n-ma):
    b_tmp += 1
  b_list.append(b_tmp)
  b_sum += b_tmp
  heappush(diff_list_asc, (b_tmp*n-ma, i))
  heappush(diff_list_dec, (ma-b_tmp*n, i))

if m<b_sum:
  while m < b_sum:
    diff, i = heappop(diff_list_dec)
    diff *= -1
    b_list[i] -= 1
    b_sum -= 1
    heappush(diff_list_dec, (-diff+n, i))
elif m>b_sum:
  while m > b_sum:
    diff, i = heappop(diff_list_asc)
    b_list[i] += 1
    b_sum += 1
    heappush(diff_list_asc, (diff+n, i))
print(*b_list)