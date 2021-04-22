N = int(input())
S_list = list(input())

count = 0
first_chosen_set = set()
for i1, s1 in enumerate(S_list):
	if s1 in first_chosen_set: continue
	first_chosen_set.add(s1)
	second_chosen_set = set()
	for i2, s2 in enumerate(S_list):
		if s2 in second_chosen_set or i1 >= i2: continue
		second_chosen_set.add(s2)
		third_chosen_set = set()
		for i3, s3 in enumerate(S_list):
			if s3 in third_chosen_set or i2 >= i3: continue

			count += 1
			third_chosen_set.add(s3)

print(count)