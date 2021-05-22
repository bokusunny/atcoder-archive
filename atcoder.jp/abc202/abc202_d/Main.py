import math

a,b,k = map(int, input().split())
ans = ""
while (a>0 and b>0):
  left = a+b
  pattern_if_select_a = math.comb(left-1, a-1)
  if k<=pattern_if_select_a:
    ans+="a"
    a-=1
  else:
    ans+="b"
    b-=1
    k-=pattern_if_select_a

if a==0:
  ans += b*"b"
elif b==0:
  ans+=a*"a"

print(ans)