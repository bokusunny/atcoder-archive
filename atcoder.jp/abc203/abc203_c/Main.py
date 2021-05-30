n, k = map(int, input().split())
dic = dict()
for i in range(n):
  a, b = map(int, input().split())
  if a in dic:
    dic[a] += b
  else:
    dic[a] = b

dic_keys = sorted(dic.keys())
left = k
current = 0
for nex in dic_keys:
  supply = dic[nex]
  if left < nex-current:
    break
  else:
    left += supply
    left -= (nex-current)
    current = nex

print(current+left)