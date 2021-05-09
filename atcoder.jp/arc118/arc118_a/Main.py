import math

t,n = map(int, input().split())

nokori_kosuu = n%t
last = 100*(n//t)

if nokori_kosuu == 0:
  exit(print(math.floor(last*(100+t)/100)-1))
last_zeikomi = math.floor(last*(100+t)/100)
for i in range(last+1, last+100):
  zeikomi = math.floor(i*(100+t)/100)
  if zeikomi-last_zeikomi == 2:
    nokori_kosuu -= 1
    if nokori_kosuu == 0:
      exit(print(zeikomi-1))

  last_zeikomi = zeikomi