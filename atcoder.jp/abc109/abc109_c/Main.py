N, X = map(int, input().split())
x_list = list(map(int, input().split()))
distance_list = []
for x in x_list:
	distance_list.append(abs(x-X))

import math
from functools import reduce

gcd_list = reduce(math.gcd, distance_list)
print(gcd_list)