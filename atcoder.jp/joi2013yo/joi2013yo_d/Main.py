day_num, clothes_num = map(int, input().split())
dp = [[0]*clothes_num for _ in range(day_num)]

temperatures = [int(input()) for _ in range(day_num)]
clothes = [list(map(int, input().split())) for _ in range(clothes_num)]

def is_wearable(cloth_i, day_i):
  cloth = clothes[cloth_i]
  cloth_min = cloth[0]
  cloth_max = cloth[1]
  temperature = temperatures[day_i]
  return cloth_min <= temperature <= cloth_max

for day_i in range(day_num-1):
  for cloth_i in range(clothes_num):
    if not is_wearable(cloth_i, day_i): continue
    for cloth_j in range(clothes_num):
      if not is_wearable(cloth_j, day_i+1): continue
      dp[day_i+1][cloth_j] = max(dp[day_i+1][cloth_j], dp[day_i][cloth_i] + abs(clothes[cloth_i][2]-clothes[cloth_j][2]))

print(max(dp[-1]))