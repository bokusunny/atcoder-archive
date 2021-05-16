n = int(input())
s = input()
t = input()
if s==t: exit(print(0))
if s.count('1') != t.count('1'): exit(print(-1))

ans = 0
s_total_0=0
t_total_0=0
for i in range(n):
  if s_total_0==t_total_0==0 and s[i]==t[i]: continue
  if s[i]=='0': s_total_0+=1
  if t[i]=='0': t_total_0+=1

  if s_total_0==t_total_0:
    ans += s_total_0
    s_total_0 = 0
    t_total_0 = 0

print(ans)