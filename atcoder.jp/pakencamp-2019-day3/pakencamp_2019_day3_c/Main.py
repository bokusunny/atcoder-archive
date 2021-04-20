N, M = map(int, input().split())
each_student_points_list = [list(map(int, input().split())) for _ in range(N)]
ans = 0
for m1_i in range(M-1):
  for m2_i in range(m1_i+1, M):
    tmp = 0
    for student_i in range(N):
      tmp += max(each_student_points_list[student_i][m1_i], each_student_points_list[student_i][m2_i])

    ans = max(ans, tmp)

print(ans)