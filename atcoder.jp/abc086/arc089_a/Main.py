import sys
input = sys.stdin.readline

N = int(input())

pre_t = 0
pre_x = 0
pre_y = 0
for i in range(N):
  t, x, y = map(int, input().split())
  t_diff = t - pre_t
  xy_diff = abs(x - pre_x) + abs(y - pre_y)

  if xy_diff > t_diff or (xy_diff - t_diff) % 2 != 0:
    print('No')
    exit()

  pre_t = t
  pre_x = x
  pre_y = y

print('Yes')