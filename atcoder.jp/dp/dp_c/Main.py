N = int(input())
dp = [[0, 0, 0], list(map(int, input().split()))]

for i in range(2, N+1):
	current_list = list(map(int, input().split()))
	max_values = [0] * 3
	for current_i, current in enumerate(current_list):
		tmp = 0
		for prev_i, prev in enumerate(dp[i-1]):
			if prev_i == current_i: continue
			sum = prev + current
			if sum > tmp:
				tmp = sum
		max_values[current_i] = tmp

	dp.append(max_values)

print(max(dp[-1]))