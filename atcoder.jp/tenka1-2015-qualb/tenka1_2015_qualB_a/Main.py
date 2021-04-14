def f(n):
  if n == 0:
    return 100
  elif n == 1:
    return 100
  elif n == 2:
    return 200
  else:
    return f(n-3) + f(n-2) + f(n-1)

print(f(19))