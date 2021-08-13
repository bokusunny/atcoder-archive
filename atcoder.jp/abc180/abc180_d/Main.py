X, Y, A, B = map(int, input().split())

cnt = 0
while 1:
  if X * A >= Y and X + B >= Y:
    break

  if X * (A-1) < B:
    X *= A
    cnt += 1
  else:
    cnt += (Y-1-X) // B
    break

print(cnt)
