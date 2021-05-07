import bisect
target_part_num, given_max = map(int, input().split())
target_part_list = [0]+[int(input()) for _ in range(target_part_num)]
twice_point_set = set()

for point1 in target_part_list:
  for point2 in target_part_list:
    twice_point_set.add(point1+point2)

twice_point_list = sorted(list(twice_point_set))

ans = 0
for first_twice_sum in twice_point_list:
  if first_twice_sum > given_max: continue
  max_second_twice_sum = given_max-first_twice_sum
  # ok = -1
  # ng = len(twice_point_list)
  # while ng-ok > 1:
  #   mid = (ok+ng) // 2
  #   if twice_point_list[mid] <= max_second_twice_sum:
  #     ok = mid
  #   else:
  #     ng = mid
  ok = bisect.bisect_left(twice_point_list, max_second_twice_sum)-1

  tmp = first_twice_sum+twice_point_list[ok]
  if ans < tmp: ans = tmp

print(ans)