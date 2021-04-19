N = int(input())
h_list = list(map(int, input().split()))
count = 0
prev = 0
for h in h_list:
	if prev < h:
		count += h-prev

	prev = h

print(count)