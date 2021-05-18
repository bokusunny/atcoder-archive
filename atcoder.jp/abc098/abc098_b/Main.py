n = int(input())
s = input()

def s_to_set(s):
	se = set()
	for c in list(s):
		se.add(c)

	return se

ans = 0
for i in range(1, n):
	left = s[:i]
	right = s[i:]

	length = len(s_to_set(left)&s_to_set(right))
	if ans < length: ans = length

print(ans)