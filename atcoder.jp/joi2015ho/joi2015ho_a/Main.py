n,m = map(int, input().split())
itinerary = []
tmp = list(map(int, input().split()))
for p in tmp:
  itinerary.append(p-1)
train_cost_list  = [tuple(map(int, input().split())) for _ in range(n-1)]

count_table = [0]*n
for i, current_city in enumerate(itinerary):
  if i == m-1: break
  next_city = itinerary[i+1]
  count_table[min(current_city, next_city)] += 1
  count_table[max(current_city, next_city)] -= 1

for i, count in enumerate(count_table):
  if i == n-1: break
  count_table[i+1] += count_table[i]

ans = 0
for i, count in enumerate(count_table):
  if i == n-1: break
  ticket_price = train_cost_list[i][0]*count
  ic_price = train_cost_list[i][1]*count+train_cost_list[i][2]
  ans += min(ticket_price, ic_price)

print(ans)