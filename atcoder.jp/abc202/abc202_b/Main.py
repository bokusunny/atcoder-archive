sl = list(input())
sl = list(reversed(sl))
for i, s in enumerate(sl):
  if s=="6":
    sl[i]="9"
  elif s=="9":
    sl[i]="6"

ans = ""
for i, s in enumerate(sl):
  ans+=s

print(ans)