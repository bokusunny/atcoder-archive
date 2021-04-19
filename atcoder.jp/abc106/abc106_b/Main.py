N = int(input())

count = 0
for i in range(1, N+1, 2):
	def calculate_divisors(n):
		return_list = []
		for i in range(1, int(n**0.5)+1):
			if n % i == 0:
				return_list.append(i)
				if i != n // i:
					return_list.append(n//i)

		return return_list

	divisors = calculate_divisors(i)
	if (len(divisors) == 8):
		count += 1

print(count)