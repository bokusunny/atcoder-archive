row_num, column_num, house_price, budget = map(int, input().split())
land_price = []
for _ in [0]*row_num:
  price_list = list(map(int, input().split()))
  land_price.append(price_list)

s = [[0]*(column_num+1) for _ in [0]*(row_num+1)]
for row_i in range(1, row_num+1):
  for column_i in range(1, column_num+1):
    s[row_i][column_i] = s[row_i][column_i-1]+s[row_i-1][column_i]-s[row_i-1][column_i-1]+land_price[row_i-1][column_i-1]

ans = 0
for smaller_row_i in range(row_num):
  for smaller_column_i in range(column_num):
    for larger_row_i in range(smaller_row_i+1, row_num+1):
      for larger_column_i in range(smaller_column_i, column_num+1):
        land_area = (larger_row_i-smaller_row_i)*(larger_column_i-smaller_column_i)
        if land_area <= ans: continue
        total_house_price = land_area * house_price
        total_land_price = s[larger_row_i][larger_column_i]-s[larger_row_i][smaller_column_i]-s[smaller_row_i][larger_column_i]+s[smaller_row_i][smaller_column_i]
        if total_house_price+total_land_price <= budget:
          ans = land_area

print(ans)