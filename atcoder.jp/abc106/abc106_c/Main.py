S = input()
K = int(input())
is_all_one = True
for i, s in enumerate(S, 1):
  if s != '1':
    first_non_zero_index = i
    first_non_zero_str = s
    is_all_one = False
    break

print(1 if is_all_one or K < first_non_zero_index else first_non_zero_str)