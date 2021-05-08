n = 10**5
def is_prime(n):
  if n<=1: return False
  i = 2
  while i*i <= n:
    if n%i == 0: return False
    i+=1

  return True

def calculate_prime_set(n):
  prime_set = set([i for i in range(2, n+1)])

  i = 2
  while i*i <= n:
    if i in prime_set and is_prime(i):
      for j in range(i*2, n+1, i):
        prime_set.discard(j)

    i+=1

  return prime_set

prime_set = calculate_prime_set(n)
prime_set.remove(2)
prime_list = []
for prime in prime_set:
  if is_prime((prime+1)//2):
    prime_list.append(prime)
prime_list.sort()

import bisect
q = int(input())
for _ in range(q):
  l,r = map(int, input().split())
  print(bisect.bisect_right(prime_list, r)-bisect.bisect_left(prime_list, l))