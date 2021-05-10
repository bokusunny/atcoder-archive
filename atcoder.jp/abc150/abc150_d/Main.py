n,m = map(int, input().split())
a_list = list(map(int, input().split()))

import math
from functools import reduce

def calculate_lcm(x, y):
  return (x * y) // math.gcd(x, y)

def lcm_list(num_list):
  return reduce(calculate_lcm, num_list, 1)

lcm = lcm_list(a_list)

for a in a_list:
  if lcm//a%2 == 0: exit(print(0))

tmp = 2*m//lcm
print(tmp//2+1 if tmp%2 == 1 else tmp//2)