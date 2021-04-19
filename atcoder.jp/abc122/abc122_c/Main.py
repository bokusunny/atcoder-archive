N, Q = map(int, input().split())
S = input()
table = [0 for _ in range(N+1)]
count = 0
for i in range(1, N):
	if S[i-1] == 'A' and S[i] == 'C':
		count += 1

	table[i] = count

table[N] = count

for _ in range(Q):
	l, r = map(int, input().split())
	print(table[r-1]-table[l-1])