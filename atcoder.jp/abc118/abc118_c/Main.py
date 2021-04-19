N = int(input())
A = list(map(int, input().split()))
import math
from functools import reduce

def gcd_list(num_list):
	return reduce(math.gcd, num_list)

gcd = gcd_list(A)
print(gcd)