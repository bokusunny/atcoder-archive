import math

A_price, B_price, AB_price, A_to_buy, B_to_buy = map(int, input().split())
total = 0
if A_price+B_price > 2*AB_price:
  min_A_B_count = min(A_to_buy, B_to_buy)
  AB_to_buy = min_A_B_count*2
  A_to_buy -= min_A_B_count
  B_to_buy -= min_A_B_count
  if A_to_buy == 0:
    print(AB_price*AB_to_buy+B_to_buy*min(AB_price*2, B_price))
  elif B_to_buy == 0:
    print(AB_price*AB_to_buy+A_to_buy*min(AB_price*2, A_price))
else:
  print(A_price*A_to_buy+B_price*B_to_buy)