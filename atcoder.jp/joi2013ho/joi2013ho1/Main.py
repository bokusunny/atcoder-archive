n = int(input())
li = list(map(int, input().split()))

table = [1]
prev_color = li[0]
for color in li[1:]:
  if color == prev_color:
    table.append(1)
  else:
    table[-1] += 1

  prev_color = color

if len(table) < 3: exit(print(n))

ans = sum(table[0:3])
prev = sum(table[0:3])
for i in range(len(table)-3):
  tmp = prev-table[i]+table[i+3]
  if tmp > ans: ans = tmp

  prev = tmp

print(ans)