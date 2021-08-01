X = input()
M = int(input())

if len(X) == 1:
  if int(X) <= M:
    exit(print(1))
  else:
    exit(print(0))


d = -1
for c in X:
  d = max(d, int(c))


def is_ok(n):
  sum = 0
  for i in reversed(range(len(X))):
    sum += int(X[i]) * pow(n, len(X) - 1 - i)
    if (sum > M):
      return False

  return True


ok = d
ng = 10**18+1
while abs(ng-ok) > 1:
  mid = (ok+ng) // 2
  if is_ok(mid):
    ok = mid
  else:
    ng = mid

print(ok - d)