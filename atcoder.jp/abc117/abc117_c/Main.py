N, M = map(int, input().split())
X = list(map(int, input().split()))
if N >= M: exit(print(0))

X.sort()
gap_list = []
for i in range(M-1):
	gap_list.append(X[i+1]-X[i])

print(sum(sorted(gap_list)[:M-N]))