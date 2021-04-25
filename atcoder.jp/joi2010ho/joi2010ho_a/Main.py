mod = 10**5
n, m = map(int, input().split())
s = [0] * n
for i in range(1, n):
  s[i] = s[i-1] + int(input())

current = 0
total_dis = 0
for _ in range(m):
  a = int(input())
  total_dis = (total_dis + abs(s[current+a]-s[current])) % mod

  current += a

print(total_dis)