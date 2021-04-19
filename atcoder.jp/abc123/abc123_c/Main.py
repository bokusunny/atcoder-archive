import math

N = int(input())
capacity = int(input())
capacities = [int(input()) for _ in range(4)]

total = prev_time = math.ceil(N/capacity)
bottle_neck_capacity = capacity
for i, capacity in enumerate(capacities, 1):
	total += 1
	if bottle_neck_capacity > capacity:
		extra_time = math.ceil((N-capacity*prev_time)/capacity)
		total += extra_time
		prev_time += extra_time
		bottle_neck_capacity = capacity

print(total)