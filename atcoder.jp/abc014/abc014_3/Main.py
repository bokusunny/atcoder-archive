n = int(input())
table = [0]*1000002
for _ in range(n):
  a, b = map(int, input().split())
  table[a] += 1
  table[b+1] -= 1

ans = table[0]
for i in range(1000001):
  table[i+1] += table[i]
  if table[i+1] > ans:
    ans = table[i+1]

print(ans)