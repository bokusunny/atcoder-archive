n = int(input())
h = []
for i in range(n):
  s,t = input().split()
  t = int(t)*-1
  h.append((t,s))

from heapq import heappop, heapify
heapify(h)
heappop(h)
t,s = heappop(h)
print(s)