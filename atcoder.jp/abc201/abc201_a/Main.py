int_list = list(map(int, input().split()))
for i in range(3):
  tmp = 0
  for j in range(3):
    if i==j: continue
    tmp+=int_list[j]
  if 2*int_list[i] == tmp:
    exit(print('Yes'))

print('No')