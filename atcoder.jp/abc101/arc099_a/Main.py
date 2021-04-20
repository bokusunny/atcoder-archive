import math

N, K = map(int, input().split())
A_list = list(map(int, input().split()))

one_index = A_list.index(1)
left = one_index
right = N-one_index-1

if left%(K-1) == 0:
  left_extra = 0
else:
  left_extra = K-left%(K-1)
left_steps = math.ceil(left/(K-1))
if right<=left_extra:
  right_steps = 0
else:
  right_steps = math.ceil((right-left_extra)/(K-1))

print(left_steps+right_steps)