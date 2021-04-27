def check(relation_set, possible_member_set):
  for mem1 in possible_member_set:
      for mem2 in possible_member_set:
        if mem1 >= mem2: continue
        if not (mem1, mem2) in relation_set:
          return False

  return True


def main():
  n, m = map(int, input().split())
  relation_set = set()
  for _ in [0] * m:
    x, y = map(int, input().split())
    relation_set.add((x-1, y-1))

  ans = 1
  for i in range(2**n):
    possible_member_set = set()
    for j in range(n):
      if (i >> j & 1):
        possible_member_set.add(j)
    is_ok = check(relation_set, possible_member_set)
    if is_ok:
      ans = max(ans, len(possible_member_set))

  print(ans)


main()