N = int(input())
A_list = list(map(int, input().split()))
A_list.sort()
B_list = list(map(int, input().split()))
C_list = list(map(int, input().split()))
C_list.sort()

import bisect
count = 0
for B in B_list:
	A_count = bisect.bisect_left(A_list, B)
	C_count = N-bisect.bisect_right(C_list, B)

	count += A_count*C_count

print(count)