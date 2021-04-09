import sys
input = sys.stdin.readline

N = int(input())
D = [int(input()) for _ in range(N)]

print(len(set(D)))