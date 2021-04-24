N = int(input())
S = input()
S_list = list(S)
Q = int(input())
T1_list = []
flipped_count = 0
for _ in range(Q):
	T, A, B = map(int, input().split())
	if T == 2:
		flipped_count += 1
	else:
		if flipped_count%2 == 1:
			if 1<=A<=N:
				A += N
			else:
				A -= N
			if 1<=B<=N:
				B += N
			else:
				B -= N

		T1_list.append((A, B))

for T1 in T1_list:
	A = T1[0]
	B = T1[1]
	S_A = S_list[A-1]
	S_B = S_list[B-1]
	S_list[A-1] = S_B
	S_list[B-1] = S_A

ans = ''.join(S_list)
if flipped_count%2 == 1:
	ans = ans[N:]+ans[:N]

print(ans)