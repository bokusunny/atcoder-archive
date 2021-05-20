def calculate_divisors(n):
  return_list = []
  for i in range(1, int(n**0.5)+1):
    if n % i == 0:
      return_list.append(i)
      if i != n // i:
        return_list.append(n//i)

  return return_list

n = int(input())
divisors_list = calculate_divisors(2*n)
divisors_list.sort()
prev = divisors_list[0]
k=-1
for divisor in divisors_list:
  if divisor-prev==1 and divisor*prev==2*n:
    k=prev
    break
  prev=divisor

if k==-1: exit(print('No'))

print('Yes')
print(k+1)
ans = [[] for _ in range(k+1)]
sum = 1
for i in range(k, 0, -1):
  for j in range(i):
    ans[k-i].append(sum+j)
    ans[k-i+j+1].append(sum+j)

  sum+=i

for i in range(k+1):
  print(k, *ans[i])