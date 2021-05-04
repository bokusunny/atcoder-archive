import sys
sys.setrecursionlimit(10**9)

n,q = map(int, input().split())

edges = dict()
for _ in range(n-1):
  a,b = map(int, input().split())
  a -= 1
  b -= 1
  if a in edges:
    edges[a].append(b)
  else:
    edges[a] = [b]
  if b in edges:
    edges[b].append(a)
  else:
    edges[b] = [a]

ans = [0]*n
def dfs(current_node, prev_val, prev_node=None):
  ans[current_node] += prev_val
  current_val = ans[current_node]
  target_edges = edges[current_node]
  if prev_node != None:
    target_edges.remove(prev_node)
  for to in target_edges:
    dfs(to, current_val, current_node)
for _ in range(q):
  p,x = map(int, input().split())
  p -= 1
  ans[p] += x

dfs(0, 0)

print(*ans)