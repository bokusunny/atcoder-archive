import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
A.sort(reverse = True)

Alice_score = 0
Bob_score = 0
for i, a in enumerate(A):
  if i % 2 == 1:
    Bob_score += a
  else:
    Alice_score += a

print(Alice_score - Bob_score)