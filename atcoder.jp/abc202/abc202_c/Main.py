n = int(input())
a_list = list(map(int, input().split()))
a_dic = dict()
for i in range(n):
  a = a_list[i]
  if a in a_dic:
    a_dic[a]+=1
  else:
    a_dic[a]=1
b_list = list(map(int, input().split()))
c_tmp = list(map(int, input().split()))
c_list = []
for c in c_tmp:
  c -= 1
  c_list.append(c)

ans = 0
for c in c_list:
  b = b_list[c]
  if b in a_dic: ans += a_dic[b]

print(ans)