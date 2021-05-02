import math

n,m = map(int, input().split())
decided_circles = []
INF = 10**30
ans = INF
for _ in range(n):
  x,y,r = map(int, input().split())
  decided_circles.append((x,y,r))
  if r < ans: ans = r

undecided_circles = []
for _ in range(m):
  x,y = map(int, input().split())
  undecided_circles.append((x, y))

for i in range(m):
  x, y = undecided_circles[i]
  for decided_circle in decided_circles:
    tmp_r = math.sqrt((decided_circle[0]-x)**2+(decided_circle[1]-y)**2)-decided_circle[2]
    if tmp_r < ans: ans = tmp_r
  for j, undecided_circle in enumerate(undecided_circles):
    if i == j: continue
    tmp_r = math.sqrt((undecided_circle[0]-x)**2+(undecided_circle[1]-y)**2)/2
    if tmp_r < ans: ans = tmp_r

print(ans)