road_num, days = map(int, input().split())
dis_list = [int(input()) for _ in range(road_num)]
weather_list = [int(input()) for _ in range(days)]

INF = 10**30

dp = [[INF]*(days+1) for _ in [0]*(road_num+1)]
dp[0][0] = 0

for day_i in range(days):
  for current_city in range(road_num):
    if dp[current_city][day_i] == INF: continue
    dp[current_city][day_i+1] = min(dp[current_city][day_i+1], dp[current_city][day_i])
    dp[current_city+1][day_i+1] = min(dp[current_city+1][day_i+1], dp[current_city][day_i]+dis_list[current_city]*weather_list[day_i])

print(min(dp[-1]))