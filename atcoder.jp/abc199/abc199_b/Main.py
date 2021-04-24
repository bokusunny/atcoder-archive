N = int(input())
A_list = list(map(int, input().split()))
B_list = list(map(int, input().split()))

if min(B_list) < max(A_list):
	print(0)
else:
	print(min(B_list)-max(A_list)+1)