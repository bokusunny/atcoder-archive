from decimal import Decimal
N, D, H = map(int, input().split())
katamuki = 10000
highest_d, highest_h = 0, 0
for _ in range(N):
  d, h = map(int, input().split())
  tmp_katamuki = Decimal((H-h)/(D-d))
  if katamuki > tmp_katamuki:
    katamuki = tmp_katamuki
    highest_d = d
    highest_h = h

ans = highest_h-highest_d*katamuki
print(ans if ans > 0 else 0)