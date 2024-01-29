import sys


A, B, V = map(int, sys.stdin.readline().rstrip().split())

day = 0
distance = 0

V -= B


result = V // (A-B)
if V % (A -B) == 0:
    print(result)

else:
    print(result+ 1)
