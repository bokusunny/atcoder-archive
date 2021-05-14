n,q = map(int, input().split())
c_list = [0]
a_list = list(map(int, input().split()))
c_tmp = list(map(int, input().split()))
for c in c_tmp:
  c_list.append(c-1)
c_list.append(0)

MOD = 10**9+7
count_table = [0]*n
for i,c in enumerate(c_list):
  if i==q+1: break
  count_table[min(c_list[i], c_list[i+1])] += 1
  count_table[max(c_list[i], c_list[i+1])] -= 1

for i in range(n-1):
  count_table[i+1] += count_table[i]

ans = 0
for i in range(n-1):
  ans = (ans+count_table[i]*pow(a_list[i], a_list[i+1], MOD))%MOD

print(ans)