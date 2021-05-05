import math

p = float(input())
def f(x):
  return x+p*(2**(-x/1.5))

def fd(x):
  return 1+p*(2**(-x/1.5))*math.log(2**(-1/1.5))

left, right = 0, p
cnt = 500
while cnt > 0:
  cnt -= 1
  mid = (left+right) / 2
  if fd(mid) == 0:
    break
  elif fd(mid) < 0:
    left = mid
  elif fd(mid) > 0:
    right = mid

print(f(mid))