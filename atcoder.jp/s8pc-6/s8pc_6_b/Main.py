def main():
  n = int(input())
  a_list = []
  b_list = []
  ab_list = []
  for _ in [0]*n:
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)
    ab_list.append((a,b))

  a_list_sorted = sorted(a_list)
  b_list_sorted = sorted(b_list)
  entrance = a_list_sorted[n//2]
  exit = b_list_sorted[n//2]

  ans = 0
  for (a, b) in ab_list:
    ans += (b-a)+abs(entrance-a)+abs(exit-b)

  print(ans)

main()