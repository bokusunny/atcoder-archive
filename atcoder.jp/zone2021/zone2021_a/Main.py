all_s = list(input())
count = 0
for s, _ in enumerate(all_s):
  if all_s[s] == 'Z' and all_s[s+1] == 'O' and all_s[s+2] == 'N' and all_s[s+3] == 'e':
      count += 1

print(count)