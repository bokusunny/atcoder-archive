N = int(input())
A_list = list(map(int, input().split()))

s_list = [0] * (N+1)
for i in range(N):
	s_list[i+1] = s_list[i]+A_list[i]

for k in range(1, N+1):
	max_val = 0
	for i in range(0, N-k+1):
		tmp = s_list[i+k]-s_list[i]
		max_val = max(max_val, tmp)

	print(max_val)