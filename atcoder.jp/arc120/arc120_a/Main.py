n = int(input())
A = list(map(int, input().split()))

max_table = []
max_table.append(A[0])
for i in range(1, n):
  if (A[i]>max_table[i-1]):
    max_table.append(A[i])
  else:
    max_table.append(max_table[i-1])

s = [A[0]]
tmp = A[0]
for i in range(1, n):
  s.append(s[i-1]+tmp+A[i])
  tmp+=A[i]

for k in range(n):
  print(s[k]+(k+1)*max_table[k])