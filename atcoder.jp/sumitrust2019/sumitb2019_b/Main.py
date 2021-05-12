n = int(input())
def f(x):
  return int(x/100*108)

for i in range(1, 50001):
  if f(i) == n:
    exit(print(i))

print(':(')