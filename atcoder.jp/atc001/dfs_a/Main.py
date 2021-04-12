def main():
  # import sys
  # input = sys.stdin.readline

  def I(): return input()
  def IS(): return input().split()
  def II(): return int(input())
  def IIS(): return map(int, input().split())
  def IIR(): return [int(input()) for _ in range(N)]
  def LIIS(): return list(map(int, input().split()))
  def ZER(N): return [False for _ in range(N)]


  INF = 10**30
  MOD = 10**9+7
  # ---------------------------------------------------
  import sys
  sys.setrecursionlimit(10 ** 9)

  H, W = IIS()
  L = []

  for i in range(H):
    s = I()
    L.append(list(s))
    if 's' in s:
      x = s.find('s')
      y = i
      start = (x, y)

  seen_set = set()
  def dfs(x, y):
    if x < 0 or (W-1) < x or y < 0 or (H-1) < y or (x, y) in seen_set:
      return False

    if L[y][x] == 'g':
      return True
    if L[y][x] == '#':
      return False

    seen_set.add((x, y))

    return dfs(x-1, y) or dfs(x+1, y) or dfs(x, y-1) or dfs(x, y+1)

  print('Yes' if dfs(x, y) else 'No')


if __name__ == "__main__":
    main()

