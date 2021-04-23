import math
from itertools import permutations

N = int(input())
coordinate_list = list()
for _ in range(N):
	x, y = map(int, input().split())
	coordinate_list.append((x, y))

def calculate_distance(num1, num2):
	coordinate1 = coordinate_list[num1]
	coordinate2 = coordinate_list[num2]

	return math.sqrt((coordinate1[0]-coordinate2[0])**2+(coordinate1[1]-coordinate2[1])**2)

per = permutations(range(0, N))
total_distance = 0
for itinerary in per:
	for i in range(N-1):
		total_distance += calculate_distance(itinerary[i], itinerary[i+1])

print(total_distance/math.factorial(N))