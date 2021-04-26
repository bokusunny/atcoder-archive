def calculate_divisors(n):
  return_list = []
  for i in range(1, int(n**0.5)+1):
    if n % i == 0:
      return_list.append(i)
      if i != n // i:
        return_list.append(n//i)

  return return_list

N = int(input())
s = [[0 for _ in range(N+1)] for _ in range(N+1)]

# N^2
for y in range(1, N+1):
  d_list = list(map(int, input().split()))
  for x in range(1, N+1):
    s[y][x] = s[y-1][x] + s[y][x-1] - s[y-1][x-1] + d_list[x-1]

#N^2 * N * N^2
max_val_list = [0]
for i in range(1, N**2+1):
  divisors_list = calculate_divisors(i)
  ans = 0
  for y_width in divisors_list:
    x_width = i//y_width
    if y_width > N or x > N: continue

    for sy in range(N-y_width+1):
      for sx in range(N-x_width+1):
        tmp = s[sy+y_width][sx+x_width] - s[sy][sx+x_width] - s[sy+y_width][sx] + s[sy][sx]
        ans = max(ans, tmp)

  less_than_p_max = max_val_list[-1]
  ans = max(less_than_p_max, ans)
  max_val_list.append(ans)


Q = int(input())
for _ in range(Q):
  p = int(input())
  print(max_val_list[p])