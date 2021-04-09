import sys
input = sys.stdin.readline

N, A, B = map(int, input().split())
sum = 0

for i in range(N+1):
  if i == 0:
    continue

  sum_of_each_digit = 0
  l = list(str(i))
  for s in l:
    sum_of_each_digit += int(s)

  if sum_of_each_digit >= A and sum_of_each_digit <= B:
    sum += i

print(sum)