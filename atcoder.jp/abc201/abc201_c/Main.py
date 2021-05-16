s_li = list(input())
must_count = 0
maybe_count = 0
for i, s in enumerate(s_li):
  if s == 'o':
    must_count+=1
  elif s == '?':
    maybe_count+=1

import math

def houjo(n, k):
  if n<k: return 0
  elif n==0: return 1
  ans = 0
  for i in range(k):
    ans += (-1)**i*math.comb(k, i)*pow(k-i,n)

  return ans

ans = 0
for must_box in range(must_count, 5):
  maybe_box = 4-must_box
  tmp = math.comb(4, must_box)*houjo(must_box, must_count)*maybe_count**maybe_box
  ans += tmp

print(ans)