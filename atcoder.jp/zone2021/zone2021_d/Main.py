S = input()
T = ''
is_reversed = False
for i in range(len(S)):
  if S[i] == 'R':
    if len(T) != 1:
      is_reversed = not is_reversed
  elif not is_reversed:
    if len(T) > 0 and T[-1] == S[i]:
      T = T[:-1]
    else:
      T += S[i]
  else:
    if len(T) > 0 and T[0] == S[i]:
      T = T[1:]
    else:
      T = S[i] + T

print(''.join(reversed(T)) if is_reversed else T)