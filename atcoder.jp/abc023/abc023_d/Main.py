n = int(input())
hs_list = []
for _ in [0]*n:
  h, s = map(int, input().split())
  hs_list.append((h,s))

def is_ok(x):
  # 貪欲法(タイムリミットが長いものから割っていく)
  process_needed_count = [0]*n # process_needed_count[k]: k秒以内に処理しなければならない風船の数
  for hs in hs_list:
    h = hs[0]
    s = hs[1]
    if x < h: return False
    time_limit = (x-h)//s
    process_needed_count[min(time_limit, n-1)] += 1 # タイムリミットがn-1秒以上の場合、いつ割ってもいい

  total = 0
  for second_from_start in range(n):
    total += process_needed_count[second_from_start]
    if total > second_from_start+1: return False # i秒後の時点で割れる風船の総数はi+1

  return True

ok = 10**14+1
ng = -1
while ok-ng > 1:
  mid = (ok+ng) // 2
  if is_ok(mid):
    ok = mid
  else:
    ng = mid

print(ok)